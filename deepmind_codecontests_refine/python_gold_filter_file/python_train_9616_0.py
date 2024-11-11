n = int(input())
N = [int(x) for x in input().split()]
even = 0
odd = 0
lastEven = 0
lastOdd = 0
for i in range(n):
    if N[i] % 2 == 0:
        even += 1
        lastEven = i+1
    else:
        odd += 1
        lastOdd = i+1
if even == 1:
    print(lastEven)
else:
    print(lastOdd)
