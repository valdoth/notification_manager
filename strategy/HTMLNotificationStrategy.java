
public class HTMLNotificationStrategy implements NotificationStrategy{
    @Override
    public String formateMessage(String message) {
        return "<html><body><h1>"+message+"</h1></body></html>";
    }
}