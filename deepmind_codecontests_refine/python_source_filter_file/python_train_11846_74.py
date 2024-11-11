x=int(input())

c=100
a=0
while c<x:
  c=c+int(c/100)
  a+=1
print(a)