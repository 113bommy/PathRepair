from time import time
from random import randrange

n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
start = time()

for i in range(n):
    if A[i] != B[i]:
        continue
    while time() - start < 1.8:
        j = randrange(n)
        if A[i] != B[j] and A[j] != B[i]:
            B[i], B[j] = B[j], B[i]
            break
    else:
        print("No")
        return

print("Yes")
print(*B)