n,k=map(int,input().split())
if n==1 and k==1:
    print(0,0)
else:
    print(min(n,k),abs(n-k)//2)






