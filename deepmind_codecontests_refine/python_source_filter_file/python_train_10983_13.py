#https://codeforces.com/problemset/problem/59/A
word_string = input()

upper = 0

for letter in word_string:
  if letter == letter.lower():
    upper -= 1
  else:
    upper += 1

if upper <0:
  print(word_string.lower())
else:
  print(word_string.upper())
