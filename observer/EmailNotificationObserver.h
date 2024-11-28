#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <mutex>
#include "NotificationObserver.h"


class EmailNotificationObserver : public INotificationObserver {
public:
    void notify(const std::string& message) const override {
        // std::lock_guard<std::mutex> lock(mtx);
        std::cout << "[Email] Notification: " << message << std::endl;
    }
};
