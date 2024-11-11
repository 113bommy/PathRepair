n = int(input())
s = input()
a = 0
for i in range(1,n):
    a = max(a,set(s[:i]) & set(s[i:]))

print(a)
