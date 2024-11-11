n = int(input())
A = list(map(int,input().split()))

a = max(A)
b = min(A)

# import sys
# if a - b > 1:
#     print("No")
#     sys.exit()

ok = 0

if a - b == 1:
    C = [0, 0]
    for i in range(n):
        C[A[i] - b] += 1
    if a - C[0] > 0 and C[1] // 2 >= a - C[0]:
        ok = 1
else:
    if n == a + 1:
        ok = 1   
    if n // 2 >= a:
        ok = 1

if ok == 1:
    print("Yes")
else:
    print("No")