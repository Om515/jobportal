public class Employee {

    // ADD EMPLOYEE
    public static void addEmployee(
        String name,
        String email,
        Date birthDate,
        String dept
    ) {

        Employee__c emp = new Employee__c(

            Employee_Name__c = name,

            Email__c = email,

            Birth_Date__c = birthDate,

            Department__c = dept
        );

        insert emp;

        System.debug('Employee Added Successfully!');
    }

    // VIEW EMPLOYEES
    public static void viewEmployees() {

        List<Employee__c> empList = [

            SELECT

                Employee_ID__c,

                Employee_Name__c,

                Email__c,

                Birth_Date__c,

                Department__c

            FROM Employee__c
        ];

        for(Employee__c e : empList) {

            System.debug(

                'ID: ' + e.Employee_ID__c +

                ' | Name: ' + e.Employee_Name__c +

                ' | Email: ' + e.Email__c +

                ' | DOB: ' + e.Birth_Date__c +

                ' | Dept: ' + e.Department__c
            );
        }
    }

    // UPDATE EMPLOYEE
    public static void updateEmployee(
        String empId,
        String newDept
    ) {

        List<Employee__c> empList = [

            SELECT
                Id,
                Department__c

            FROM Employee__c

            WHERE Employee_ID__c = :empId

            LIMIT 1
        ];

        if(empList.size() > 0) {

            empList[0].Department__c = newDept;

            update empList;

            System.debug('Employee Updated Successfully!');

        } else {

            System.debug('Employee Not Found!');
        }
    }

    // DELETE EMPLOYEE
    public static void deleteEmployee(String empId) {

        List<Employee__c> empList = [

            SELECT Id

            FROM Employee__c

            WHERE Employee_ID__c = :empId

            LIMIT 1
        ];

        if(empList.size() > 0) {

            delete empList;

            System.debug('Employee Deleted Successfully!');

        } else {

            System.debug('Employee Not Found!');
        }
    }

    // MENU
    public static void menu() {

        System.debug('------ Employee Management ------');

        System.debug('1. Add Employee');

        System.debug('2. View Employees');

        System.debug('3. Update Employee');

        System.debug('4. Delete Employee');

        System.debug('--------------------------------');
    }
}




object name id Employee
fields Employee Name, Email, Birth Date, Department(picklist) , Employee ID (auto number)

Employee.addEmployee(
    'Rohan',
    'rohan@gmail.com',
    Date.newInstance(2003,5,10),
    'IT'
);
