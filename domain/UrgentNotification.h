#pragma once
#include "Notification.h"
#include <iostream>
#include <string>

 class UrgentNotification final : public Notification {
public:
    UrgentNotification(const std::string& msg) : Notification(msg) {}
    void send() const override {
        std::cout << "Sending UR1GENT Notification: " << message << std::endl;
    }
};