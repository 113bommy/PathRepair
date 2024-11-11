n, k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

x, y = 0, max(B) + k + 1
z = (x + y)//2
while z != x:
    credit = 0
    for i in range(n):
        credit += max(z*A[i] - B[i], 0)
    if credit > k:
        y = z
    else:
        x = z
    z = (x + y)//2
print(z)
