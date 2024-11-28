#pragma once
#include <vector>
#include <memory>

#include "../observer/NotificationObserver.h"

class NotificationManager {
    private:
        std::vector<std::shared_ptr<INotificationObserver>> observers;

        // Constructeur privé
        NotificationManager() = default;

    public:
        // Constructeur par défaut supprimé
        NotificationManager(const NotificationManager&) = delete;
        NotificationManager& operator=(const NotificationManager&) = delete;

        // Accès unique à l'instance
        static NotificationManager& getInstance() {
            static NotificationManager instance; // Thread-safe Singleton
            return instance;
        }

        void addObserver(std::shared_ptr<INotificationObserver> observer) {
            observers.push_back(observer);
        }

        void notifyAll(const std::string& message) {
            for (const auto& observer : observers) {
                observer->notify(message);
            }
        }
    };
