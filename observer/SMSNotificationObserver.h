#pragma once
#include <string>
#include <mutex>
#include <iostream>
#include "NotificationObserver.h"

class SMSNotificationObserver : public INotificationObserver {
public:
    void notify(const std::string& message) const override {
        // std::lock_guard<std::mutex> lock(mtx);
        std::cout << "[SMS] Notification: " << message << std::endl;
    }
};