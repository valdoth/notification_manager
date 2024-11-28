#pragma once
#include <string>
#include <iostream>
#include "NotificationObserver.h"

class PushNotificationObserver : public INotificationObserver {
public:
    void notify(const std::string& message) const override {
        std::cout << "Push Notification: " << message << std::endl;
    }
};