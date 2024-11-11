s = input()
res = 0

for char in s:
    if (char in ('a', 'e', 'i', 'o', 'u', '0', '2', '4', '6', '8')):
        res += 1

print(res)