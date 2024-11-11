n=int(input())
l=list(map(int,input().split()))
if n==1 and sum(l)==1:
    print("YES")
elif ( sum(l)==n-1  )  :
    print("YES")
else:
    print("NO")