public class JSONNotificationStrategy implements NotificationStrategy
{
    @Override
    public String formateMessage(String message) {
        return "{message: "+message+"}";
    }
}