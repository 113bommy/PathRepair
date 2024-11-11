n=int(input())
a=list(map(int,input().split()))
t,f=0,0
for x in a:
  if x%4==0:
    f+=1
  elif x%2==0:
    t+=1
print('Yes' if max(0,t-1)+f*2+1>=n else 'No')