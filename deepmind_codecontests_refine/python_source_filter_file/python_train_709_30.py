N = int(input())
lst = [int(x) for x in input().split()]
a = 0
b = 0
for n in lst:
    if n % 4 == 0:
        a += 1
    elif n == 2:
        b += 1

if b >= 2:
    N = N - (b - 1)

if a >= N // 2:
    print("Yes")
else:
    print("No")
