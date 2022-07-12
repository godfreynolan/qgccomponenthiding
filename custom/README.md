# Custom QGroundControl: AUVSI

## Getting Started
Clone the repo including submodules:
```bash
git clone --recursive -j8 https://github.com/mavlink/qgroundcontrol.git
```
Update submodules (required each time you pull new source code):
```bash
git submodule update --recursive
```
## Building the Custom Version of QGC

To build this custom version:

* Clean the build directory of any previous build (Right click project name in QtCreator and select 'Clean')
* Change to the `custom` directory
* Run `python updateqrc.py`
* Build QGC from QtCreator

## Debugging/Logging to the Console
### C++
To debug or print text to the QtCreator console in your C++ files, you can do things like the following:

```cpp
#include <QDebug>

qDebug() << "Hi I am debugging stuff haha";
qInfo()  << "Hi, I'm Windows 7. Did you know a USB device was just plugged into your computer!"
```
### QML

Logging text to the console is exactly the same as logging in Javascript

```js
console.log("Wow, a console.log(\"Wow, a console.log()... How incredible...\")... How incredible...")
```
## Communication Between QML and C++
To communicate between C++ and QML, there are a few things one must do.

#### Setup for C++ files

1. Make sure the properties/variables you want shared from C++ to QML are attributes on C++ class that has the type `Q_Object`

    a. For example, our [CustomCorePlugin](src/CustomCorePlugin.h) class has that typing, and it looks something like the following:
    ```cpp
    class CustomCorePlugin : public QGCCorePlugin {
        Q_OBJECT;
        ...
    ```

2. Declare the property you want visible under QML with the prefix helper method `Q_PROPERTY` or with the prefix `Q_INVOKABLE` if you want to make a specific method callable from QML

    a. For the full list of things you can specify in the Q_PROPERTY macro, visit [here](https://doc.qt.io/qt-5/properties.html)
    ```cpp
    class ExampleClass {
        Q_OBJECT;
        
        public:
            ExampleClass();

            Q_PROPERTY(PropertyType myProperty READ myProperty WRITE setMyProperty NOTIFY myPropertyChanged)
            Q_INVOKABLE void setMyProperty(PropertyType newValue);
            Q_INVOKABLE std::string getMySecretCode();

            PropertyType myProperty() { return _myProperty; };

        protected:
            PropertyType _myProperty;
    };
    ```

3. Before moving on to define these methods, ensure you have included the necessary header files, such as `#include <QObject>`.

    *a. Note: Including `QObject` is not necessary for files that include `QGCCorePlugin.h`*

4. Now, go on to define your undefined methods from the header file in your source file. For reference, please take a look at [CustomCorePlugin.cc](src/CustomCorePlugin.cc)

### Use setTimeout() in QML!
Visit this [link](https://stackoverflow.com/questions/28507619/how-to-create-delay-function-in-qml) for further reference

Add `import QtQml 2.12` to the top of your QML file

Add the following somewhere in your QML file:
```qml
Timer {
    id: timer
    function setTimeout(ms, callback) {
        timer.interval = ms;
        timer.repeat = false;
        timer.triggered.connect(callback);
        timer.triggered.connect(function destroy() {
            timer.triggered.disconnect(callback);
            timer.triggered.disconnect(destroy);
        });
        timer.start();
    }
}
```

Then, simply call it like `timer.setTimeout(100, yourCallbackFunction)` where required
#### Setup for QML files
In the QML file you wish to have properties from C++ files, do the following:

1. Define a QML Module by creating a `qmldir` file in the same folder as your qml component. More details can be found [here](https://doc.qt.io/qt-5/qtqml-modules-topic.html)

2. Set the module name by writing `Module MyModule.SubModule` at the top of the file

3. Import the module in which your C++ property lives

    a. For custom QGC and properties built off the core plugin, you can simply write the following at the top of your QML file: `import QGroundControl 1.0`

4. Declare your property in the root object of your QML file
    ```qml
    LegitQMLObject {
        id: myLegitObjectId

        property propertyType myProperty: MyModule.SubModule.myProperty
        property string propertyOnQGC_CorePlugin: QGroundControl.corePlugin.propertyFromQGC
    }
    ```

![Custom Build Screenshot](README.jpg)

More details on what a custom build is and how to create your own can be found in the [QGC Dev Guide](https://dev.qgroundcontrol.com/en/custom_build/custom_build.html).


> Important Note: This custom build is not automatically built each time regular QGC code changes. This can mean that it may fall out of date with the latest changes in QGC code. This can show up as the `python updateqrc.py` steps failing due to upstream resource changes. Or possibly fail to compile because the plugin mechanism for custom builds has changed. If this happens please notify the QGC devs and they will bring it up to date. Or even better, submit a pull for the fix yourself!