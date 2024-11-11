n = int(input())

s = [int(x) for x in input().split()]

sorted(s)
rev = sorted(s, reverse=True)

x = y = 0
for i in range(n//2):
    x += rev[i]
    y += s[i]

if n%2 != 0:
    x += s[n//2]

print(x*x + y*y)