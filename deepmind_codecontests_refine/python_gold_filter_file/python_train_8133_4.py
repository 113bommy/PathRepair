n,k = map(int,input().split())
if k==1 or k==n: print(6+(n-2)*3)
else: print(8+min(k,n-k+1)+(n-3)*3)