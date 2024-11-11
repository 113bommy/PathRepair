__author__ = "runekri3"

VOWELS = list("aeiouy")
CONSONANTS = list("bcdefghjklmnpqrstvwxyz")

question = input()

for letter in reversed(question):
    if letter in VOWELS:
        print("YES")
        break
    elif letter in CONSONANTS:
        print("NO")
        break
