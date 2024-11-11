n = int(input())
a = list(map(int,input().split()))

x=0
y=0
a.sort()
i=len(a)
while (i>1):
  if a[i-1]==a[i]:
    x=y
    y=a[i]
    i-=2
  else:
    i+=1
  if y>0:
    break

print(x*y)