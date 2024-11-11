n,a,b=map(int,input().split())
num=0
for i in range (n+1):
  if 2 <= sum(list(map(int,list(str(i)))))<=5:
    num+=i
print(num)
