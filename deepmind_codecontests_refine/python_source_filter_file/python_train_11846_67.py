X=int(input())
ans=100
cnt=0
while ans<X:
  ans+=int(ans/100)
  cnt+=1
print(cnt)