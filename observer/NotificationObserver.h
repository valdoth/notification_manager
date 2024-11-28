#pragma once 
#include <string>
#include <mutex>


class INotificationObserver {
    public:
        virtual void notify(const std::string& message) const = 0;
        virtual ~INotificationObserver() = default; // Destructeur virtuel
        std::mutex mtx;
};