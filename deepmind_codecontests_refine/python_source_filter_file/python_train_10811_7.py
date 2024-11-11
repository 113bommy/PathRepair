n=int(input())
s=input()
x=0
max=0
for i in range(n):
  if(s[i]=="D"):
    x-=1
  else:
    x+=1
    max=max([max,x])
print(max)