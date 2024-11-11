import math
h,w=map(int,input().split())
ans,cnt=h*w,0
if h%3==0 or w%3==0:
  ans=0
else:
  for i in range(1,h):
    cnt=max((h-i)*(w%2),abs(math.floor(w/2)*(h-i)-w*i),abs(math.ceil(w/2)*(h-i)-w*i))
    ans=min(ans,cnt)
  for i in range(1,w):
    cnt=max((w-i)*(h%2),abs(math.floor(h/2)*(w-i)-h*i),abs(math.ceil(h/2)*(w-i)-h*i))
    ans=min(ans,cnt)
print(ans)
