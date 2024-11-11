n=int(input())
ans=2*(n//3)
if n<=2:
    ans=1
elif n//3==0:
    ans=2*(n//3)
else:
    ans=2*(n//3)+1
print (ans)
