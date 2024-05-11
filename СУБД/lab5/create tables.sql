-- �������� ������� "��������"
CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    FirstName NVARCHAR(50),
    LastName NVARCHAR(50),
    FacultyID INT,  -- ������� ����, ��������� �� ������� "����������"
    GPA DECIMAL(3,2)  -- ������� ���� ��������
);

-- �������� ������� "����������"
CREATE TABLE Faculties (
    FacultyID INT PRIMARY KEY,
    FacultyName NVARCHAR(100)
);

-- �������� ������� "����������"
CREATE TABLE Courses (
    CourseID INT PRIMARY KEY,
    CourseName NVARCHAR(100),
    Credits INT  -- ���������� �������� ������
);

-- �������� ������� "��������_����������" ��� ����� ������ �� ������
CREATE TABLE StudentCourses (
    StudentID INT,
    CourseID INT,
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID),
    PRIMARY KEY (StudentID, CourseID)
);