H,N=map(int,input().split())
A=[int(i) for i in input().split()]
print('Yes' if H<=sum(A) else "No")