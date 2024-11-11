n,x=map(int,input().split())
if x==1 or x==2*n-1:print("No");exit()
print("Yes")
if n==2:print(*[1,2,3],sep="\n")
else:
 l=list(range(1,2*n))
 if x==2:a=[3,2,1,4]
 else:a=[n-1,n,n+1,n-2]
 l=list(set(l)-set(a))
 m=len(l)//2
 b=l[:m]+a+l[m:]
 print(*b,sep="\n")