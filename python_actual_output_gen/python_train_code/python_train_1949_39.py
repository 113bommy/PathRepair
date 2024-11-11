a,b=map(int,input().split())
if a*b<0:
  ans=(abs(abs(a)-abs(b))+1)
elif a*b==0:
  ans=(max(abs(a),abs(b)))
  if min(a,b)<0:
    ans+=1
elif a<b:
  ans=(b-a)
else:
  ans=(a-b+2)
print(ans)