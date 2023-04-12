#include <iostream>
#include <string>
class Students
{
private:
    std::string studName;
    int studAge;
    std::string studCourse;
    int id;
    int yearLevel;
    int mathSub;
    int engSub;
    int filSub;
    int mapehSub;
    int scieSub;

public:
    Students(std::string name, int age, std::string course, int userId, int year)
    {
        studAge = age;
        studName = name;
        studCourse = course;
        id = userId;
        yearLevel = year;
        mathSub = 0;
        engSub = 0;
        filSub = 0;
        mapehSub = 0;
        scieSub = 0;
    }

    std::string getStudName()
    {
        return studName;
    }

    void setMath(int grade)
    {
        mathSub = grade;
    }


    void setEng(int grade)
    {
        engSub = grade;
    }


    void setfil(int grade)
    {
        filSub = grade;
    }


    void setMapeh(int grade)
    {
        mapehSub = grade;
    }


    void setScie(int grade)
    {
        scieSub = grade;
    }

    void setStudName(std::string newName) 
    {
        studName = newName;
    }

    void setStudAge(int newAge)
    {
        studAge = newAge;
    }


    void setStudCourse(std::string newCourse)
    {
        studCourse = newCourse;
    }
        
    void setYearLevel(int newYearLevel)
    {
        yearLevel = newYearLevel;
    }

    int getId() {
        return id;
    }


    void showStudents()
    {
        std::cout << "\n==================================================\n";

        std::cout << "Name: " << studName  << "\n";
        std::cout << "Age: " << studAge << "\n";
        std::cout << "Course: " << studCourse << "\n";
        std::cout << "Year Level: " << yearLevel << "\n";
        std::cout << "ID: " << id;

        std::cout << "\nStudent Grades:" << "\n";
    
        std::cout << "Math: " << mathSub << "\n";
        std::cout << "English: " << engSub << "\n";
        std::cout << "Filipino: " << filSub << "\n";
        std::cout << "Mapeh: " << mapehSub << "\n";
        std::cout << "Science: " << scieSub;
 
        std::cout << "\n==================================================\n";
    }
};

class StudentManagement
{

private:
    Students* studArr[50] = {nullptr};
    int studentArrSize;
    Students* tempHolder;
public:
    StudentManagement()
    {
        
         studentArrSize = 0;
    }

    void addStud(Students *student)
    {
        studArr[studentArrSize] = student;
        studentArrSize++;
    }

    void deleteStud(std::string studDel)
    {
        for (int i = 0; i < studentArrSize; i++)
        {
            if (studDel == studArr[i]->getStudName())
            {
                delete studArr[i];
                studArr[i] = nullptr;

                std::cout << "Student deleted!" << std::endl;
                break;
            }
        }
    }

    void showStud()
    {
     
        for (int i = 0; i < studentArrSize; i++)
        {

            for (int j = 0; j < studentArrSize - i - 1; j++) {
                if (studArr[i] != nullptr && studArr[i]->getStudName() > studArr[i + 1]->getStudName())

                     tempHolder = studArr[j];
                studArr[j] = studArr[j + 1];
                studArr[j + 1] = tempHolder;
                
            }
            studArr[i]->showStudents();
        }
    }



    void searchUser(std::string findUser)
    {

        for (int i = 0; i < studentArrSize; i++)
        {
            if (studArr[i]->getStudName() == findUser)
            {
                std::cout << "User  found."
                          << "\n";
                studArr[i]->showStudents();
            }
            else
            {
                std::cerr << "User not found."
                          << "\n";
            }
        }
    }

    void editGrades() {
        int idInput;
        int editStudDecider;
        int setMath;
        int setEng;
        int setFil;
        int setMapeh;
        int setScience;
        std::string operationDecider;
        bool flag = true;
        std::cout << "Enter id of the student: ";
        std::cin >> idInput;
            
        for (int i = 0; i < studentArrSize; i++) {
            
            if (studArr[i]->getId() == idInput)
            {
                std::cout << "User  found."
                    << "\n";

                studArr[i]->showStudents();
                while (flag) {

                    std::cout << "\n -----------------------------------\n";

                    std::cout << "\n   Please choose actions to perform\n"
                        << "\n";

                    std::cout << "                 Edit Math[1]"
                        << "\n\n";
                    std::cout << "              Edit English[2]"
                        << "\n\n";
                    std::cout << "             Edit Filipino[3]"
                        << "\n\n";
                    std::cout << "                Edit MAPEH[4]"
                        << "\n\n";
                    std::cout << "              Edit Science[5]"
                        << "\n\n";
                    std::cout << "                      Exit[6]"
                        << "\n";

                    std::cout << "\n -----------------------------------\n";

                    std::cin >> editStudDecider;
                    switch (editStudDecider) {

                    case 1:

                        std::cout << "Enter Math grade: ";
                        std::cin >> setMath;
                        studArr[i]->setMath(setMath);

                        break;

                    case 2:

                        std::cout << "Enter English grade: ";

                        std::cin >> setEng;
                        studArr[i]->setEng(setEng);

                        break;

                    case 3:

                        std::cout << "Enter Filipino grade: ";

                        std::cin >> setFil;
                        studArr[i]->setfil(setFil);

                        break;

                    case 4:

                        std::cout << "Enter MAPEH grade: ";

                        std::cin >> setMapeh;
                        studArr[i]->setMapeh(setMapeh);

                        break;

                    case 5:

                        std::cout << "Enter Science grade: ";

                        std::cin >> setScience;
                        studArr[i]->setScie(setScience);

                        break;

                    case 6: flag = false;
                        break;

                        std::cout << "Enter Science grade: ";

                        std::cin >> setScience;
                        studArr[i]->setScie(setScience);

                        break;


                    default: std::cout << "operation not found.";

                        break;
                    }

                    std::cout << "\nUpdated Student Grades" << "\n";
                    studArr[i]->showStudents();

                    
                }
               
            }
            else
            {
                std::cerr << "User not found."
                    << "\n";
            }

        }
    
    
    }


    void editStud() {
        int idInput;
        int editStudDecider;
        int setAge;
        int setNewYearLevel;
        std::string setCourse;
        std::string setName;
        std::string operationDecider;
        std::cout << "Enter id of the student: ";
        std::cin >> idInput;
        bool flag = true;
        for (int i = 0; i < studentArrSize; i++) {

            if (studArr[i]->getId() == idInput)
            {
                std::cout << "User  found."
                    << "\n";

                studArr[i]->showStudents();
               

                while (flag) {
                        
                    std::cout << "\n -----------------------------------\n";

                    std::cout << "\n   Please choose actions to perform\n"
                        << "\n";

                    std::cout << "              Edit Name[1]"
                        << "\n\n";
                    std::cout << "               Edit Age[2]"
                        << "\n\n";
                    std::cout << "            Edit Course[3]"
                        << "\n\n";
                    std::cout << "        Edit Year Level[4]"
                        << "\n\n";

                    std::cout << "                   Exit[5]"
                        << "\n";

                    std::cout << "\n -----------------------------------\n";

                    std::cin >> editStudDecider;
                    switch (editStudDecider) {

                    case 1:

                        std::cout << "Enter new name: ";
                        std::getline(std::cin >> std::ws, setName);
                        studArr[i]->setStudName(setName);

                        break;

                    case 2:

                        std::cout << "Enter new age: ";

                        std::cin >> setAge;
                        studArr[i]->setStudAge(setAge);

                        break;

                    case 3:

                        std::cout << "Enter new course: ";

                        std::getline(std::cin >> std::ws, setCourse);
                        studArr[i]->setStudCourse(setCourse);

                        break;

                 

                    case 4:

                        std::cout << "Enter new year level: ";

                        std::cin >> setNewYearLevel;
                        studArr[i]->setYearLevel(setNewYearLevel);

                        break;
                    
                    case 5: flag = false;
                      
                        break;

                    default: std::cout << "operation not found.";

                        break;
                    }

                    std::cout << "\nUpdated Student" << "\n";
                    studArr[i]->showStudents();

                   
                   
                  
                }
                

               
            }
            else
            {
                std::cerr << "User not found."
                    << "\n";
            }

        }


    }

};

int main()
{
    int decider;
    std::string operationDecider;
    StudentManagement studManagement;
    std::string enterName;
    int enterAge;
    int enterYearLevel;
    std::string enterCourse;
    int numbersOfStudents;
    std::string deleteStud;
    int studentId = 0;
    std::string findStud;

    while (true)
    {
        std::cout << "\n -----------------------------------\n";

        std::cout << "\n   Please choose actions to perform\n"
                  << "\n";

        std::cout << "              Add Student[1]"
                  << "\n\n";
        std::cout << "        View Class Record[2]"
                  << "\n\n";
        std::cout << "           Delete Student[3]"
                  << "\n\n";
        std::cout << "           Search Student[4]"
                  << "\n\n";
        std::cout << "            Edit Student [5]"
            << "\n\n";
        std::cout << "             Edit Grades [6]"
            << "\n";

        std::cout << "\n -----------------------------------\n";

        std::cout << "Answer: ";
        std::cin >> decider;

        switch (decider)
        {
        case 1:
            std::cout << "How many numbers of students would you like to add."
                      << "\n";

            std::cout << "Answer: ";
            std::cin >> numbersOfStudents;

            std::cout << "\n";

            for (int i = 0; i < numbersOfStudents; i++)
            {
                studentId++;
                std::cout << "-----------------------------------\n";

                std::cout << "Enter Name: ";
                std::getline(std::cin >> std::ws, enterName);
         
                std::cout << "Enter Age: ";
                std::cin >> enterAge;

                std::cout << "Enter Student Course: ";
                std::getline(std::cin >> std::ws, enterCourse);
                

                std::cout << "Enter Year Level: ";
                std::cin >> enterYearLevel;

                std::cout << "-----------------------------------\n";
                Students *student = new Students(enterName, enterAge, enterCourse, studentId, enterYearLevel);

                studManagement.addStud(student);
            }

            break;
        case 2:

            studManagement.showStud();

            break;

        case 3:

            std::getline(std::cin >> std::ws, deleteStud);

            studManagement.deleteStud(deleteStud);

            break;
        case 4:

            std::cout << "Search user by full name: ";

            std::getline(std::cin >> std::ws, findStud);

            studManagement.searchUser(findStud);

            break;

        case 5: studManagement.editStud();
            break;

        case 6: studManagement.editGrades();
            break;

        default:

            std::cout << "Operation not found\n";

            break;
        }

        std::cout << "Do you want to do another operation?(y/n)"
                  << "\n";
        std::cout << "Answer: ";
        std::cin >> operationDecider;
        if (operationDecider != "y" && operationDecider != "Y")
        {
            break;
        }
    }

    return 0;
}