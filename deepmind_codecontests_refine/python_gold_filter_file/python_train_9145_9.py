K,T = map(int,input().split())
A = list(map(int,input().split()))
print(max(2*max(A)-K-1,0))