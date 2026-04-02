# CS50 – Readability

## Description

This program analyzes a block of text and determines its reading grade level using the Coleman-Liau index.

## How it works

The program:

1. Counts the number of letters, words, and sentences in the text
2. Calculates the average number of letters and sentences per 100 words
3. Applies the Coleman-Liau formula to compute the readability index
4. Outputs the corresponding U.S. grade level

## Usage

```
make readability
./readability
```

## Example

```
Text: Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, "and what is the use of a book," thought Alice "without pictures or conversation?"
Grade 8
```

## Concepts

- String manipulation
- Character classification (isalpha, isspace)
- Loops
- Functions and modularity
- Floating-point arithmetic
