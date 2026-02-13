# 🍽️ Purvangika’s Restaurant  
### C++ Restaurant Management & Billing System  

Purvangika’s Restaurant is a console-based Restaurant Management and Billing System built using C++.  
This project simulates a real-world restaurant ordering and billing workflow using Object-Oriented Programming principles.

---

## 📌 Project Overview

This system allows customers to:

- View a categorized food menu  
- Add items with quantity  
- Update quantity if the same item is selected again  
- Remove items from the cart  
- Generate a detailed bill  
- Apply discount automatically  
- Calculate GST  
- Select payment method (Cash / Card / UPI)  

The program ensures proper input validation and structured order handling.

---

## 🧠 Concepts Used

This project demonstrates strong understanding of:

- Object-Oriented Programming (OOP)
- Classes and Objects
- Encapsulation
- Abstraction
- STL (Vectors)
- Conditional Logic
- Real-world billing implementation
- Input validation handling

---

## 🏗️ Project Structure

### 1️⃣ MenuItem Class  
Stores:
- Item ID  
- Name  
- Price  
- Category  

### 2️⃣ OrderedItem Structure  
Stores:
- Selected MenuItem  
- Quantity ordered  

### 3️⃣ Restaurant Class  
Handles:
- Menu display  
- Order management  
- Item removal  
- Bill generation  
- Discount & GST calculation  
- Payment processing  

---

## 💰 Billing Logic

- Subtotal = Sum of (Price × Quantity)  
- 10% Discount applied if subtotal > ₹500  
- 5% GST applied after discount  
- Final total calculated clearly  
- Payment confirmation displayed  

---

## 🛠️ Technologies Used

- C++
- Standard Template Library (STL)
- Console-based interface
- Object-Oriented Programming principles

---

## ▶️ How to Run

### Compile:
```
g++ restaurant.cpp -o restaurant
```

### Run:
```
./restaurant
```

---

## 🎯 Learning Outcomes

Through this project, I strengthened my understanding of:

- Designing structured software systems  
- Managing dynamic data using vectors  
- Implementing real-world business logic  
- Writing clean and modular C++ code  

---

## 🔮 Future Improvements

- File handling for saving receipts  
- Admin login system  
- Database integration  
- Bill number & timestamp generation  
- GUI-based version  

---

## 👩‍💻 Author

**Purvangika Kanwar**  
B.Tech Computer Science (2nd Year)

---

⭐ If you found this project useful, feel free to star the repository!

👩‍💻 Author

Purvangika Kanwar
Second Year Computer Science Student
