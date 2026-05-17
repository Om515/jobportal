public class StudentContro {

    // Object for form input
    public Student__c stu {get; set;}

    // List to display records
    public List<Student__c> studentList {get; set;}

    // Constructor
    public StudentContro() {

        stu = new Student__c();

        loadStudents();
    }

    // Load all students
    public void loadStudents() {

        studentList = [
            SELECT Id,
                   Name,
                   Student_Name__c,
                   Roll_Number__c,
                   Email__c,
                   Marks__c
            FROM Student__c
            ORDER BY CreatedDate DESC
        ];
    }

    // Save student
    public PageReference saveStudent() {

        insert stu;

        stu = new Student__c();

        loadStudents();

        return null;
    }

    // Delete student
    public PageReference deleteStudent() {

        String studentId = ApexPages.currentPage()
                        .getParameters()
                        .get('delId');

        Student__c s = [
            SELECT Id
            FROM Student__c
            WHERE Id = :studentId
        ];

        delete s;

        loadStudents();

        return null;
    }
}




<apex:page controller="StudentContro">

    <apex:form >

        <!-- FORM -->

        <apex:pageBlock title="Student Record Management System">

            <apex:pageBlockSection columns="1">

                <!-- Student Name -->

                <apex:inputText value="{!stu.Student_Name__c}"
                    label="Student Name"/>

                <!-- Roll Number -->

                <apex:inputText value="{!stu.Roll_Number__c}"
                    label="Roll Number"/>

                <!-- Email -->

                <apex:inputText value="{!stu.Email__c}"
                    label="Email"/>

                <!-- Marks -->

                <apex:inputText value="{!stu.Marks__c}"
                    label="Marks"/>

                <!-- Save Button -->

                <apex:commandButton value="Save Student"
                    action="{!saveStudent}"
                    rerender="studentTable"/>

            </apex:pageBlockSection>

        </apex:pageBlock>

        <br/>

        <!-- STUDENT TABLE -->

        <apex:pageBlock title="Student Records"
            id="studentTable">

            <apex:pageBlockTable value="{!studentList}"
                var="s">

                <!-- Auto Number -->

                <apex:column value="{!s.Name}"
                    headerValue="Record ID"/>

                <!-- Student Name -->

                <apex:column value="{!s.Student_Name__c}"
                    headerValue="Student Name"/>

                <!-- Roll Number -->

                <apex:column value="{!s.Roll_Number__c}"
                    headerValue="Roll Number"/>

                <!-- Email -->

                <apex:column value="{!s.Email__c}"
                    headerValue="Email"/>

                <!-- Marks -->

                <apex:column value="{!s.Marks__c}"
                    headerValue="Marks"/>

                <!-- Delete -->

                <apex:column headerValue="Action">

                    <apex:commandLink value="Delete"
                        action="{!deleteStudent}">

                        <apex:param name="delId"
                            value="{!s.Id}"/>

                    </apex:commandLink>

                </apex:column>

            </apex:pageBlockTable>

        </apex:pageBlock>

    </apex:form>

</apex:page>


auto number