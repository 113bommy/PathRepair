n=int(input())
a=[int(i) for i in input().split()]
x=0
b=[]
for i in a:
  if i<0: x=(x+1)%2
  b.append(abs(i))
b.sort()
print(sum(b)-b[0] if  x else sum(b))