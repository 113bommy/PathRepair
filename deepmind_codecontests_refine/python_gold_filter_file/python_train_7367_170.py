L,R,d = map(int,input().split())
ans = R//d - L//d
if L%d==0:
  ans+=1
print(ans)
