n,k = map(int,input().split())
hn = [int(input()) for i in range(n)]

hn.sort()

print(min(hn[i+k-1] - hn[i] for i in range(n-k+1)))