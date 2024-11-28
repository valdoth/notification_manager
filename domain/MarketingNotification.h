#pragma once
#include "Notification.h"
#include "../singleton/NotificationManager.h"
#include <iostream>
#include <string>

class MarketingNotification : public Notification {
public:
    MarketingNotification(const std::string& msg) : Notification(msg) {}
    void send() const override {
        std::cout << "Sending MARKETING notification: " << message << std::endl;
        NotificationManager::getInstance().notifyAll(message);
    }
};