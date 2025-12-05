# 📘 Department Diary – Activity Monitoring System (C Project)

A console-based **Department Diary Management System** built in C for our first-semester programming project.
This system helps manage and monitor all department-related activities throughout the semester using basic file handling and structured programming concepts.

---

## ✨ Features

* ➕ Add new activities
* 📄 View all saved activities
* ✏️ Edit existing entries
* ❌ Delete records
* 🔍 Search by task, date, or location
* 📅 View activities scheduled for today
* 💾 Data stored using **file handling** (diary.txt)

---

## 🧱 Tech Used

* C Programming
* File Handling (read/write operations)
* Structures (`struct Activity`)
* Menu-driven console interface

---

## 📂 File Structure

```
project/
│── diary.c        # Main program
│── diary.txt      # Auto-generated database file
│── README.md      # Project documentation
```

---

## 🚀 How It Works

1. On startup, the program loads existing data from `diary.txt`
2. Users can add, edit, search, or delete department activities
3. On exit, all updates are saved back to the file
4. Even after closing the program, your data is preserved

---

## 🛠️ How to Run

```bash
gcc diary.c -o diary
./diary
```

---

## 📮 Feedback

Feel free to **fork this repo**, suggest improvements, or report issues.
I’m open to ideas to make this project better!

---
