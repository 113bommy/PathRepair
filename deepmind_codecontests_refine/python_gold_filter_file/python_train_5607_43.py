x,y = map(int,input().split())
d = abs(abs(x)-abs(y))
if y>=x>=0 or 0>=y>=x:
  ans = d
elif x>y>0 or 0>x>y:
  ans = d + 2
else:
  ans = d + 1
print(ans)