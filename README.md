# File Encrypter/Decrypter

This C++ tool uses the Caesar cipher to encrypt and decrypt files and directories on a byte level. It reads the encryption key from a `.env` file and employs multithreading for enhanced performance.

## Features

- **Byte-Level Encryption/Decryption:** Uses the Caesar cipher for files and directories.
- **Multithreading:** Speeds up processing with multiple threads.
- **C++17:** Developed with C++17.

## Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/your-username/file-encrypter-decrypter.git
   ```

2. **Navigate to the project directory:**
   ```bash
   cd file-encrypter-decrypter
   ```

3. **Build the project:**
   ```bash
   g++ -std=c++17 -o file_encrypter_decrypter main.cpp
   ```

## Usage

1. **Create a `.env` file in the working directory with the encryption key (e.g., `3`).**

2. **Run the program:**

## Notes

- Ensure the `.env` file is correctly formatted and present in the working directory.
- The Caesar cipher is a basic encryption technique and may not be suitable for secure applications.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE.txt) file for details.

---

Feel free to adjust any details as needed!
