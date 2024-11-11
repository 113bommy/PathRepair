n=int(input())
flag=0
ans=""
for y in range(6):
    n_=(n-(4*y))
    if n_<0:
        n_=n
    if n_%7==0:
      flag=1
      x=int((n-(4*y))/7)
      ans=('4'*y)+('7'*x)
      break
if flag==0:
    print(-1)
else:
    print(ans)
