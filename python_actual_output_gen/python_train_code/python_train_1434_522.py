a,b=map(int,input().split())
i=1
while a*i-(i-1)<b:
  i+=1
print(i)