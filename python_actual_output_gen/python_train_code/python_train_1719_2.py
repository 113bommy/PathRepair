N,K = map(int,input().split())
a = sorted(map(int,input().split()))

count = N
s = 0
for i in range(N-1,-1,-1):
    if s + N[i] < K:
        s += N[i]
    else:
        count = min(i,count)
print(count)
