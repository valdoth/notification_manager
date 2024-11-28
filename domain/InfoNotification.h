#pragma once
#include "Notification.h"
#include <iostream>
#include <string>

class InfoNotification final : public Notification {
public:
    InfoNotification(const std::string& msg) : Notification(msg) {}
    void send() const override {
        std::cout << "Sending INFO Notification: " << message << std::endl;
    }
};