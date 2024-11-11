n=int(input())
ans=0
b=380000
for i in range(n):
  x,u=input().split()
  if u=="JPY":
    ans+=int(x)
  else:
    ans+=int(x)*b
print(ans)