-- Создание таблицы "Студенты"
CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    FirstName NVARCHAR(50),
    LastName NVARCHAR(50),
    FacultyID INT,  -- Внешний ключ, ссылается на таблицу "Факультеты"
    GPA DECIMAL(3,2)  -- Средний балл студента
);

-- Создание таблицы "Факультеты"
CREATE TABLE Faculties (
    FacultyID INT PRIMARY KEY,
    FacultyName NVARCHAR(100)
);

-- Создание таблицы "Дисциплины"
CREATE TABLE Courses (
    CourseID INT PRIMARY KEY,
    CourseName NVARCHAR(100),
    Credits INT  -- Количество зачётных единиц
);

-- Создание таблицы "Студенты_Дисциплины" для связи многие ко многим
CREATE TABLE StudentCourses (
    StudentID INT,
    CourseID INT,
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID),
    PRIMARY KEY (StudentID, CourseID)
);