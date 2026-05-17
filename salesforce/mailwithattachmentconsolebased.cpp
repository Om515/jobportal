public class MailWithAttachment {

    // Method to Send Email With Attachment
    public static void sendEmailWithAttachment() {

        // Create Email Object
        Messaging.SingleEmailMessage mail =
            new Messaging.SingleEmailMessage();

        // Set Recipient Email
        mail.setToAddresses(
            new String[] { 'omsatpute111@gmail.com' }
        );

        // Set Subject
        mail.setSubject(
            'Apex Email With Attachment'
        );

        // Set Email Body
        mail.setPlainTextBody(
            'Hello,\n\n' +
            'Please find the attachment.\n\n' +
            'Thank You!'
        );

        // Create Attachment Object
        Messaging.EmailFileAttachment attachment =
            new Messaging.EmailFileAttachment();

        // Multi-line File Content
        String content =
            'Hello,\n' +
            'This is sample attachment file.\n' +
            'It contains multiple lines.\n\n' +
            'Apex is powerful.\n' +
            'Email sent successfully.\n\n' +
            'Regards,\n' +
            'Salesforce';

        // Set File Name
        attachment.setFileName(
            'SampleFile.txt'
        );

        // Convert Content Into Blob
        attachment.setBody(
            Blob.valueOf(content)
        );

        // Set MIME Type
        attachment.setContentType(
            'text/plain'
        );

        // Attach File To Email
        mail.setFileAttachments(
            new Messaging.EmailFileAttachment[] { attachment }
        );

        // Send Email
        Messaging.sendEmail(
            new Messaging.SingleEmailMessage[] { mail }
        );

        // Debug Message
        System.debug(
            'Email With Attachment Sent Successfully!'
        );
    }
}