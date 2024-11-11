n = int(input())
p = [int(input()) for _ in range(n)]

q = [0] * n
for i in range(n):
    q[p[i]-1] = i
mxk = 1
k = 1
for i in range(n-1):
    if q[i] < q[i+1]:
        k += 1
        if k > mxk:
            mxk = k
    else:
        k = 1
print(n-mxk)
