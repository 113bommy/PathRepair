n = int(input())
arr = [int(p) for p in input().split()]
preSum = [arr[0]]
for i in range(1, len(arr)):
    preSum.append(preSum[i-1]+arr[i])
q = int(input())
for i in range(q):
    a, b = [int(p) for p in input().split()]
    a -= 1; b-=1
    if a != 0:
        cumSum = preSum[b]-preSum[a]
    else:
        cumSum = preSum[b]
    print(cumSum//10)