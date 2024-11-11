import sys
from math import ceil
read=lambda:sys.stdin.readline().strip()
write=lambda x:sys.stdout.write(x+"\n")
N=int(read())
SA=list(map(int, read().split()));
SB=list(map(int, read().split()));
arrA = [0 for _ in range(5)]
arrB = [0 for _ in range(5)]
for i in range(N):
    arrA[SA[i]-1] += 1
    arrB[SB[i]-1] += 1
result = 0
for i in range(5):
    s = arrA[i] + arrB[i]
    diff = abs(arrA[i]-arrB[i])
    diff /= 2
    if s % 2:
        result = -1
        break
    result += diff

if result > 0:
    result = int(ceil(result/2))

write(str(result))
    