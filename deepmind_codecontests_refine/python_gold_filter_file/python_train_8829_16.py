N = int(input())
A = list(map(int,input().split()))
tmp = sorted([A[i-1]-i for i in range(1,N+1)])
B = tmp[N//2]
print(sum([abs(t-B) for t in tmp]))