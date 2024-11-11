n=eval(input())
l=list(map(int,input().split()))
l=sorted(l,reverse=True)
c=0
sum=l[0]+l[1]+l[2]+l[3]+l[4]+l[5]+l[6]+l[7]+l[8]+l[9]+l[10]+l[11]
if(n>sum):
  print(-1)
else:
  i=0
  d=0
  c=0
  while(i<=11 and d<n):
    d+=l[i]
    c+=1
    i+=1
    
  print(c)
