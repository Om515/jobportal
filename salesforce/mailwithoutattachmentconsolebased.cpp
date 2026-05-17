public class MailWithoutAttachment {

    // Method to Send Email
    public static void sendSimpleEmail() {

        // Create Email Object
        Messaging.SingleEmailMessage mail =
            new Messaging.SingleEmailMessage();

        // Set Recipient Email
        mail.setToAddresses(
            new String[] { 'omsatpute111@gmail.com' }
        );

        // Set Email Subject
        mail.setSubject(
            'Test Email From Apex'
        );

        // Set Email Body
        mail.setPlainTextBody(
            'Hello,\n\n' +
            'This is a test email sent using Apex in Salesforce.\n\n' +
            'Thank You!'
        );

        // Send Email
        Messaging.sendEmail(
            new Messaging.SingleEmailMessage[] { mail }
        );

        // Debug Message
        System.debug(
            'Email Sent Successfully!'
        );
    }
}