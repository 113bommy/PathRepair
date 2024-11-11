n = int(input())
s = input()
count = 0
for c in range(n-1):
    if s[c] == s[c+1]:
        count += 1
print(count)