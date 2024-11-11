a=int(input())
t=0
p=100
while p<a:
  p+=(p/100)
  t+=1
print(t)