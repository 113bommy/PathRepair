tag = {'1':-1,'2':1}
def f():
    n = int(input())
    A = [tag[s] for s in input().split()]
    left = A[:n]
    right = A[n:][::-1]
    count = {0:0}  # rem
    sum = 0
    for i in range(n):
        sum += left[i]
        count[sum] = i+1
    maxRem = count[0]
    sum = 0
    for j in range(n):
        sum += right[j]
        if (-sum) in count:
            maxRem = max(maxRem, count[-sum] + j+1)
    return 2*n - maxRem


t = int(input())
for i in range(t):
    print(f())