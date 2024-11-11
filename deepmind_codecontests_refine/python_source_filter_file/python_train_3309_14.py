s, t = input().split()
a, b = map(int, input().split())
u = input()

if s == t:
    a -= 1
else:
    b -= 1

print(a, b)