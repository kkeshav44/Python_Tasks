# KESHAV THAKUR

import random

#  List of 5 predefined words
word_list = ["apple", "train", "house", "plant", "snake"]

#  Pick a random word from the list
secret_word = random.choice(word_list)

guessed_letters = []
wrong_guesses = 0
max_attempts = 6

print(" Welcome to Hangman!")
print("Guess the word one letter at a time.")
print(f"You have {max_attempts} wrong attempts allowed.\n")

#  Game loop
while True:
    display_word = ""
    for letter in secret_word:
        if letter in guessed_letters:
            display_word += letter + " "
        else:
            display_word += "_ "

    print("Word:", display_word.strip())

    if all(letter in guessed_letters for letter in secret_word):
        print("\n Congratulations! You guessed the word:", secret_word)
        break

    
    guess = input("Enter a letter: ").lower()


    if len(guess) != 1 or not guess.isalpha():
        print("❗ Please enter a single alphabet letter.\n")
        continue

    
    if guess in guessed_letters:
        print(" You already guessed that letter. Try another one.\n")
        continue
    guessed_letters.append(guess)

    if guess in secret_word:
        print("Good guess!\n")
    else:
        wrong_guesses += 1
        print(f"Wrong guess! Attempts left: {max_attempts - wrong_guesses}\n")

    # Check if the player has used all attempts
    if wrong_guesses >= max_attempts:
        print(" Game Over! You've been hanged!")
        print("The correct word was:", secret_word)
        break
