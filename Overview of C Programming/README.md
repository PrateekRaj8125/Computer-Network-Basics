# 🖥️ Overview of C Programming  

This folder contains programs that review essential **C programming concepts** required as a foundation for **Computer Networks**.  
It focuses on functions, pointers, structures, and system-level concepts like **endianness**, which are critical for understanding how data is represented and transmitted across networks.  

---

## 📘 Coverage  

- Functions & Pointers in C  
- Structures and Nested Structures  
- Call by Value vs Call by Address  
- Command Line Arguments  
- Endianness (Little Endian vs Big Endian)  

---

## 📝 Assignments  

1. **Swap using Pointers**  
   - Write a C program to swap the content of two variables entered through the command line using functions and pointers.
   - Code File - [swap pointers](https://github.com/PrateekRaj8125/CN_Lab/blob/main/Overview%20of%20C%20Programming/swap_pointers.c) 

2. **Structure Operations**  
   - Assign values to a structure (`student_info`) and pass it:  
     - By value  
     - By address  
   - Print all structure members in both cases.  

    ```
    struct student_info {
      int roll_no;
      char name[50];
      float CGPA;
      struct dob age;
    };
    ```

    - Code File - [call by value and call by address](https://github.com/PrateekRaj8125/CN_Lab/blob/main/Overview%20of%20C%20Programming/structure_call_by_value%20and%20call_by_address.c)

3. Extract Bytes from a Number
    - Write a C program to extract each byte from a number, store them in separate variables, and print them.
    - Code File - [extract bytes](https://github.com/PrateekRaj8125/CN_Lab/blob/main/Overview%20of%20C%20Programming/extract_bytes.c)

4. Store and Reconstruct a Number using Structure
    - Enter a number, store it across a structure, print each member, then reconstruct the original number.

   ```
    struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
    };
   ```
    - Code File - [pkt structure](https://github.com/PrateekRaj8125/CN_Lab/blob/main/Overview%20of%20C%20Programming/pkt_structure.c) 

5. Check Endianness
    - Write a C program to check whether the host machine is Little Endian or Big Endian.
    - Print the content of each byte and convert endianness (Little ↔ Big).
    - Code File - [endianness](https://github.com/PrateekRaj8125/CN_Lab/blob/main/Overview%20of%20C%20Programming/endianness.c)
  
## ▶️ How to Compile & Run

Use GCC to compile and run programs:

```bash
  # Example: Swap program
  gcc swap_pointers.c -o swap
  ./swap 10 20
```

```bash
  # Example: Endianness check
  gcc endianness.c -o endian
  ./endian
```

## 🎯 Purpose

- Strengthen C programming basics before diving into socket programming

- Understand how data representation affects communication across networks

- Build confidence in handling pointers, memory, and structures in C
