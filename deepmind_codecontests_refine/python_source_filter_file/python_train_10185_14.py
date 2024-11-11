a=int(input())
b=int(input())
c=int(input())
x=int(input())
cnt=0
for i in range(a+1):
  for j in range(b+1):
    for k in range(c+1):
      if a*500+b*100+c*50==x:
        cnt+=1
print(cnt)