k,t = map(int,input().split())
A = list(map(int,input().split()))
print(max(2*max(A) - sum(A) -1))