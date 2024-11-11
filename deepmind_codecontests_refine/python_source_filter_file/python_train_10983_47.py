# https://codeforces.com/problemset/problem/59/A

s = input()

character_upper = 0
character_lower = 0

for i in s:
    if i.isupper():
        character_upper += 1
    else:
        character_lower += 1

if character_lower > character_upper:
    print(s.lower())
else:
    print(s.upper())