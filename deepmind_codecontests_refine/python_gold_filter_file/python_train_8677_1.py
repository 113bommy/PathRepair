from math import sqrt, floor; from itertools import count, islice
maxV = 2**20
n = int(input())
buffer = {4}
bufferNotPrime = [True]*maxV
nums = list(map(int, input().split()))

for i in range(2, maxV):
    if bufferNotPrime[i]:
        for j in range(i*i, maxV, i):
            bufferNotPrime[j] = False
        buffer.add(i*i)
for i in nums:
    if i in buffer: 
        print("YES")
    else:
        print("NO")