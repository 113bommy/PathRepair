n=int(input())
ans=2*(n//3)
if n<=2:
    ans=1
elif n//3!=0:
    ans=ans+1
print (ans)
