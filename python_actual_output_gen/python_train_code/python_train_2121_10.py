n = int(input())
s = input()
first_letter = s[0]
last_letter = s[-1]
total = 1

i = 0

while s[i] == first_letter and i < len(s):
    i += 1
total += i


j = 0
i = len(s) - 1
while s[i] == last_letter and 0 <= i:
    i -= 1
    j += 1
total += j

if first_letter == last_letter:
    total += i * j
    
print(total % 998244353)