public class StudentContro {

    // Object for Form Input
    public Student__c stu {get; set;}

    // List for Displaying Records
    public List<Student__c> studentList {get; set;}

    // Constructor
    public StudentContro() {

        stu = new Student__c();

        loadStudents();
    }

    // Load All Students
    public void loadStudents() {

        studentList = [

            SELECT Id,
                   Name,
                   Student_Name__c,
                   Roll_Number__c,
                   Class__c,
                   Mobile_No__c
            FROM Student__c
            ORDER BY CreatedDate DESC
        ];
    }

    // Save Student Record
    public PageReference saveStudent() {

        insert stu;

        // Clear Form
        stu = new Student__c();

        // Reload Table
        loadStudents();

        return null;
    }

    // Delete Student Record
    public PageReference deleteStudent() {

        // Get Student Id
        String studentId = ApexPages.currentPage()
                        .getParameters()
                        .get('delId');

        // Fetch Record
        Student__c s = [

            SELECT Id
            FROM Student__c
            WHERE Id = :studentId
        ];

        // Delete Record
        delete s;

        // Reload Table
        loadStudents();

        return null;
    }
}




<apex:page controller="StudentContro">

    <apex:form>

        <!-- STUDENT FORM -->

        <apex:pageBlock title="Student Record Management System">

            <apex:pageBlockSection columns="1">

                <!-- Student Name -->

                <apex:inputText
                    value="{!stu.Student_Name__c}"
                    label="Student Name"/>

                <!-- Roll Number -->

                <apex:inputText
                    value="{!stu.Roll_Number__c}"
                    label="Roll Number"/>

                <!-- Class -->

                <apex:inputText
                    value="{!stu.Class__c}"
                    label="Class"/>

                <!-- Mobile Number -->

                <apex:inputText
                    value="{!stu.Mobile_No__c}"
                    label="Mobile Number"/>

                <!-- Save Button -->

                <apex:commandButton
                    value="Save Student"
                    action="{!saveStudent}"
                    rerender="studentTable"/>

            </apex:pageBlockSection>

        </apex:pageBlock>

        <br/>

        <!-- STUDENT RECORD TABLE -->

        <apex:pageBlock
            title="Student Records"
            id="studentTable">

            <apex:pageBlockTable
                value="{!studentList}"
                var="s">

                <!-- Auto Number -->

                <apex:column
                    value="{!s.Name}"
                    headerValue="Auto Number"/>

                <!-- Student Name -->

                <apex:column
                    value="{!s.Student_Name__c}"
                    headerValue="Student Name"/>

                <!-- Roll Number -->

                <apex:column
                    value="{!s.Roll_Number__c}"
                    headerValue="Roll Number"/>

                <!-- Class -->

                <apex:column
                    value="{!s.Class__c}"
                    headerValue="Class"/>

                <!-- Mobile Number -->

                <apex:column
                    value="{!s.Mobile_No__c}"
                    headerValue="Mobile Number"/>

                <!-- Delete Button -->

                <apex:column headerValue="Action">

                    <apex:commandLink
                        value="Delete"
                        action="{!deleteStudent}"
                        rerender="studentTable">

                        <apex:param
                            name="delId"
                            value="{!s.Id}"/>

                    </apex:commandLink>

                </apex:column>

            </apex:pageBlockTable>

        </apex:pageBlock>

    </apex:form>

</apex:page>

auto number

auto number
