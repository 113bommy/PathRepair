# A. Pangram
# time limit per test2 seconds
# memory limit per test256 megabytes
# inputstandard input
# outputstandard output
# A word or a sentence in some language is called a pangram if all the characters of the alphabet of this language appear in it at least once. Pangrams are often used to demonstrate fonts in printing or test the output devices.

# You are given a string consisting of lowercase and uppercase Latin letters. Check whether this string is a pangram. We say that the string contains a letter of the Latin alphabet if this letter occurs in the string in uppercase or lowercase.

# Input
# The first line contains a single integer n (1 ≤ n ≤ 100) — the number of characters in the string.

# The second line contains the string. The string consists only of uppercase and lowercase Latin letters.

# Output
# Output "YES", if the string is a pangram and "NO" otherwise.
from collections import defaultdict

LATIN_LETTERS = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'y', 'z']

def solve_the_problem():
	size = int(input())
	word = input()

	if size < 24:
		print("NO")
		return

	our_letters = set(sorted(word.lower()))
	print(sorted(our_letters))
	for letter in LATIN_LETTERS:
		if letter not in our_letters:
			print("NO")
			return
	
	print("YES")




if __name__ == "__main__":
    solve_the_problem()

