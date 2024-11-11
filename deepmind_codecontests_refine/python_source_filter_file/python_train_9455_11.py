N = int(input())
A = list(map(int, input().split()))

A.sort()
x = A[-1]
A.pop()

z = x

for a in A:
    if abs(x-a*2) < abs(x-z*2):
        z = a

print(x, z)