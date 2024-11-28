#include <memory>
#include <thread>
#include <future>
#include "./domain/Notification.h"
#include "domain/InfoNotification.h"
#include "domain/MarketingNotification.h"
#include "domain/UrgentNotification.h"
#include "./observer/EmailNotificationObserver.h"
#include "./observer/NotificationObserver.h"
#include "./observer/PushNotificationObserver.h"
#include "./observer/SMSNotificationObserver.h"
#include "./singleton/NotificationManager.h"



void simulateAsyncNotification(const std::shared_ptr<Notification>& notification) {
        std::thread t([notification]() {
            notification->send();
        });
        t.join();
    }


int main() {
    // Exemple avec make_shared
    auto emailObserver = std::make_shared<EmailNotificationObserver>();
    auto smsObserver = std::make_shared<SMSNotificationObserver>();

    // Gestionnaire de notifications (Singleton)
    auto& manager = NotificationManager::getInstance();
    manager.addObserver(emailObserver);
    manager.addObserver(smsObserver);

    // Notifications avec polymorphisme
    auto infoNotification = std::make_shared<InfoNotification>("System Update Available");
    auto urgentNotification = std::make_shared<UrgentNotification>("Critical Security Alert");

    // Envoi des notifications et appel de notifyAll
    infoNotification->send();
    manager.notifyAll("System Update Available"); // Notifier tous les observateurs

    urgentNotification->send();
    manager.notifyAll("Critical Security Alert");

    // Utilisation de std::future et std::async pour des calculs asynchrones
    auto futureTask = std::async(std::launch::async, []() {
        return "Async Task Completed";
    });

    std::cout << futureTask.get() << std::endl;

    return 0;
}
