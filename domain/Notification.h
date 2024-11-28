#pragma once
#include <string>

class Notification {
protected:
    std::string message;

public:
    Notification(const std::string& msg) : message(msg) {}
    virtual void send() const = 0; // Méthode virtuelle pure
    virtual ~Notification() = default; // Destructeur virtuel
};