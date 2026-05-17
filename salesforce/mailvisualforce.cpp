public class EmailController {

    // Variables
    public String toEmail { get; set; }
    public String subject { get; set; }
    public String body { get; set; }

    // Attachment Variables
    public String fileName { get; set; }
    public Blob fileBody { get; set; }


    // Method To Send Email
    public PageReference sendEmail() {

        // Simple Email Validation
        if (
            toEmail == null ||
            !toEmail.contains('@') ||
            !toEmail.contains('.') ||
            toEmail.contains(' ')
        ) {

            ApexPages.addMessage(
                new ApexPages.Message(
                    ApexPages.Severity.ERROR,
                    'Invalid Email ID'
                )
            );

            return null;
        }

        // Create Email Object
        Messaging.SingleEmailMessage mail =
            new Messaging.SingleEmailMessage();

        // Set Recipient
        mail.setToAddresses(
            new String[] { toEmail }
        );

        // Set Subject
        mail.setSubject(subject);

        // Set Body
        mail.setPlainTextBody(body);

        // Attach File If Uploaded
        if (fileBody != null) {

            Messaging.EmailFileAttachment attachment =
                new Messaging.EmailFileAttachment();

            attachment.setFileName(fileName);

            attachment.setBody(fileBody);

            mail.setFileAttachments(
                new Messaging.EmailFileAttachment[] { attachment }
            );
        }

        // Send Email
        Messaging.sendEmail(
            new Messaging.SingleEmailMessage[] { mail }
        );

        // Success Message
        ApexPages.addMessage(
            new ApexPages.Message(
                ApexPages.Severity.CONFIRM,
                'Email Sent Successfully!'
            )
        );

        // Clear Form
        toEmail = '';
        subject = '';
        body = '';
        fileName = '';
        fileBody = null;

        return null;
    }
}






<apex:page controller="EmailController">

    <!-- Header -->
    <apex:sectionHeader title="Email Service"
        subtitle="Send Notification"
    />

    <!-- Form -->
    <apex:form id="theForm"
        enctype="multipart/form-data"
    >

        <!-- Success/Error Messages -->
        <apex:pageMessages />

        <!-- Main Page Block -->
        <apex:pageBlock title="Email Composer">

            <apex:pageBlockSection columns="1">

                <!-- Recipient Email -->
                <apex:inputText label="To Address"
                    value="{!toEmail}"
                    required="true"
                />

                <!-- Subject -->
                <apex:inputText label="Subject"
                    value="{!subject}"
                />

                <!-- Email Body -->
                <apex:inputTextarea label="Body"
                    value="{!body}"
                    rows="8"
                    cols="60"
                />

                <!-- File Upload -->
                <apex:pageBlockSectionItem >

                    <apex:outputLabel value="Select Attachment"
                    />

                    <apex:inputFile value="{!fileBody}"
                        filename="{!fileName}"
                    />

                </apex:pageBlockSectionItem>

            </apex:pageBlockSection>

            <!-- Send Button -->
            <apex:pageBlockButtons location="bottom">

                <apex:commandButton action="{!sendEmail}"
                    value="Send Email"
                />

            </apex:pageBlockButtons>

        </apex:pageBlock>

    </apex:form>

</apex:page>