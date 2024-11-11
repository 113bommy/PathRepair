s=int(input())
a=100
b=0
while a<=s:
  a=int(a*(1+0.01))
  b+=1
print(b)