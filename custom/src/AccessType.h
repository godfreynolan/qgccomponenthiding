#pragma once
#include <string>
#ifndef ACCESSTYPE_H

enum AccessType { Basic, Expert, Factory };

std::string accessTypeString(AccessType accessType);

#define ACCESSTYPE_H
#endif // ACCESSTYPE_H