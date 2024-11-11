t1,t2 = map(int,input().split())
a1,a2 = map(int,input().split())
b1,b2 = map(int,input().split())
p1 = t1*a1
q1 = t1*b1
p2 = p1+t2*a2
q2 = q1+t2*b2
if p2 == q2:
  print("infinity")
  exit()
if (p1>q1 and p2>q2) or (p1<q1 and p2<q2):
  print(0)
  exit()
x = abs(p1-q1)
y = abs(q2-p2)
if x%y == 0:
  ans = (x//y)*2-2
else:
  ans = (x//y)*2+1
print(ans)
  