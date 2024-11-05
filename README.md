# Basic Banking System Application

## Overview

This project is a simple console-based banking system application built in C++. My friend and I developed it during our third semester of our diploma program as an introductory project to practice Object-Oriented Programming (OOP) concepts and file handling in C++. The application allows users to create and manage bank accounts, view account details, and perform basic transactions like deposits, withdrawals, and balance checks.

## Features

1. **Account Creation**: Users can create new bank accounts by entering details such as name, age, Aadhar number, and PIN for security.
2. **Basic Transactions**: Users can:
   - **Check Account Balance**
   - **Deposit Funds**
   - **Withdraw Funds**
3. **Manager Login**: The manager can view all account information by entering a password.
4. **User Authentication**: Basic PIN-based authentication ensures security for users.

## Project Structure

The code is organized into classes representing different roles and functionalities:

- **BankAccount**: Manages account details and creation.
- **Transaction**: Handles deposits, withdrawals, and balance checks.
- **Manager**: Provides access to view all account details.
- **Customer**: Represents the user interacting with the system.

## Getting Started

### Prerequisites

- **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., GCC, Visual Studio).

### How to Run

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/BasicBankingSystem.git

2. **Navigate to the Project Directory**:
   ```bash
   cd BasicBankingSystem

3. **Compile the Code**:
   ```bash
   g++ BankingSystem.cpp -o BankingSystem

4. **Run the Executable**:
   
   - On Window:
     ```bash
     g++ BankingSystem.cpp -o BankingSystem

   - On Unix/Linux:
     ```bash
     ./BankingSystem

## Usage

1. **Account Creation**: Users can create new bank accounts by entering details such as name, age, Aadhar number, and PIN for security.
2. **Create Account**: Users can:
   - **Check Account Balance**
   - **Deposit Funds**
   - **Withdraw Funds**
3. **Manager Login**: The manager can view all account information by entering a password.
4. **User Authentication**: Basic PIN-based authentication ensures security for users.


## Future Enhancements
1. **Online Banking Integration**: Enabling online banking functionality for users to access their accounts remotely.
2. **Enhanced Security**: Adding features like two-factor authentication and account lockout after multiple failed attempts.
3. **Graphical User Interface (GUI)**: Transitioning from a console-based to a GUI-based application for a better user experience.
4. **Transaction History**: Allowing users to view a history of their transactions for better financial tracking.
