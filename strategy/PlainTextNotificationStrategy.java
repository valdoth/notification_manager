public class PlainTextNotificationStrategy implements NotificationStrategy{
    @Override
    public String formateMessage(String message) {
        return message;
    }
}