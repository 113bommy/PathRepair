t = int(input())

for i in range(t):
    n = int(input())
    m = list(map(int, input().split()))
    mMax = -10000000000
    sum = 0
    for j in range(n):
        if m[j] >= mMax:
            mMax = m[j]
        sum += m[j]
    sum -= mMax
    sum /= n-1
    print(sum+mMax)