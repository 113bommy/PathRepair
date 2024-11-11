import math
N = int(input())

a = math.ceil(N**0.5)-1

cnt=0
for i in range(1,a):
    if N%i == 0:
        if i < (N//i)-1:
            cnt += (N//i)-1
print(cnt)
