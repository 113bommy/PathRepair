from math import ceil
a=int(input())
b=list(map(int, input().split()))
c=[]
cnt=0
for i in range(a):
  if b. count(b[i])==2 and b[i]>0:
    cnt+=1
  elif b. count(b[i])>2 and b[i]>0:
    print("-1")
    quit()
  else:
    cnt+=0
print(ceil(cnt/2))
    