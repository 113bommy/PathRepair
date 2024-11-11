n = int(input())
s = [0] * (n+1)
for i in map(int, input().split()):
    s[i] += i
a = b = 0
for i in s:
    a, b = max(a, b), a+i
print(a)
