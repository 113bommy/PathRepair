n=int(input())
d=int(input())
e=int(input())
e*=5 
ans=n 
for i in range(n//e):
    ans=min(ans,(n-i*e)%d )
print(ans)    