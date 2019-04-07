#ifndef FMODEXCEPTION
#define FMODEXCEPTION

#include <FMOD/fmod_errors.h>
#include <string>
#include <stdexcept>

class fmodException : public std::runtime_error
{
public:
    fmodException(const std::string& message, FMOD_RESULT errCode)
        : std::runtime_error(message + std::string(FMOD_ErrorString(errCode))) { }
};

class fmodExceptionCritical : public fmodException
{
public:
    using fmodException::fmodException; //use fmodException's constructors
};

#endif //FMODEXCEPTION 