n = int(input())
s = input()
counter = 0
for c in s:
    if c == '8':
        counter += 1

print(min(n // 11, counter))
