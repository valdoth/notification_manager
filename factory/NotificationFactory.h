#include <memory>

#include "../enums/NotificationType.h"
#include "../domain/Notification.h"
#include "../domain/InfoNotification.h"
#include "../domain/UrgentNotification.h"
#include "../domain/MarketingNotification.h"
#include <stdexcept>

class NotificationFactory {
public:
    static std::unique_ptr<Notification> createNotification(const std::string& message, NotificationType type) {
        switch (type) {
            case NotificationType::INFO:
                return std::make_unique<InfoNotification>(message);
            case NotificationType::URGENT:
                return std::make_unique<UrgentNotification>(message);
            case NotificationType::MARKETING:
                return std::make_unique<MarketingNotification>(message);
            default:
                throw std::invalid_argument("Unknown Notification Type");
        }
    }
};