n = int(input())
a = list(map(int, input().split()))
a = sorted(a)
minus = len([i for i in a if i < 0])
if minus == 0:
  minus = 1
elif minus == len(a):
  minus = len(a)-1
  
print(sum(a[minus:])- sum(a[:minus]))
for e in a[minus:-1]:
  print(str(a[0])+" "+str(e))
  a[0] -= e
for e in a[:minus]:
  print(str(a[-1])+" "+str(e))
  a[-1] -= e