n = int(input())
s = str(input())

while (len(s)-1) % n != 0:
    s = s[:len(s)-1]

sol = 0
for i in range(len(s)-1, 3, -n):
    if s[i-1] == s[i-2] and s[i-2] == s[i-3]: sol += 1

print(sol)
