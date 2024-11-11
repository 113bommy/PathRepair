n = int(input())
s = input()
a = []
for i in range(n):
    a.append(s[i])
a.sort()
s = ""
for i in range(n):
    s += a[i]
print(s)
