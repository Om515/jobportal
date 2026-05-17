public class Bank {

    // =========================
    // ADD EMPLOYEE
    // =========================
    public static void addEmployee(
        String name,
        String email,
        Date birthDate,
        String dept
    ) {

        Bank__c emp = new Bank__c(

            // CHANGED:
            // OLD API NAME  -> Emp_Name__c
            // NEW API NAME  -> Employee_Name__c
            Employee_Name__c = name,

            // SAME API NAME
            Email__c = email,

            // SAME API NAME
            Birth_Date__c = birthDate,

            // SAME API NAME
            Department__c = dept
        );

        insert emp;

        System.debug('Employee Added Successfully!');
    }

    // =========================
    // VIEW EMPLOYEES
    // =========================
    public static void viewEmployees() {

        List<Bank__c> empList = [

            SELECT

                // CHANGED:
                // OLD API NAME -> Emp_ID__c
                // NEW API NAME -> Employee_ID__c
                Employee_ID__c,

                // CHANGED:
                // OLD API NAME -> Emp_Name__c
                // NEW API NAME -> Employee_Name__c
                Employee_Name__c,

                // SAME API NAME
                Email__c,

                // SAME API NAME
                Birth_Date__c,

                // SAME API NAME
                Department__c

            FROM Bank__c
        ];

        for(Bank__c e : empList) {

            System.debug(

                // CHANGED:
                // OLD -> e.Emp_ID__c
                // NEW -> e.Employee_ID__c
                'ID: ' + e.Employee_ID__c +

                // CHANGED:
                // OLD -> e.Emp_Name__c
                // NEW -> e.Employee_Name__c
                ' | Name: ' + e.Employee_Name__c +

                // SAME
                ' | Email: ' + e.Email__c +

                // SAME
                ' | DOB: ' + e.Birth_Date__c +

                // SAME
                ' | Dept: ' + e.Department__c
            );
        }
    }

    // =========================
    // UPDATE EMPLOYEE
    // =========================
    public static void updateEmployee(
        String empId,
        String newDept
    ) {

        List<Bank__c> empList = [

            SELECT
                Id,
                Department__c

            FROM Bank__c

            // CHANGED:
            // OLD API NAME -> Emp_ID__c
            // NEW API NAME -> Employee_ID__c
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

    // =========================
    // DELETE EMPLOYEE
    // =========================
    public static void deleteEmployee(String empId) {

        List<Bank__c> empList = [

            SELECT Id

            FROM Bank__c

            // CHANGED:
            // OLD API NAME -> Emp_ID__c
            // NEW API NAME -> Employee_ID__c
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

    // =========================
    // MENU
    // =========================
    public static void menu() {

        System.debug('------ Employee Management ------');

        System.debug('1. Add Employee');

        System.debug('2. View Employees');

        System.debug('3. Update Employee');

        System.debug('4. Delete Employee');

        System.debug('--------------------------------');
    }
}



object name : Bank
fields : Employee Name, Email, Birth Date, Department