N,K = map(int,input().split())
lis = [int(input()) for x in range(N)]
lis.sort()
print(min(lis[i+K-1] - lis[i] for x in range(N-K+1)))