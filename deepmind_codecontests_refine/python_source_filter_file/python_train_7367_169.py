L,R,d = map(int,input().split())
ans = R//d - L//d
if R%d==0:
  ans+=1
print(ans)
