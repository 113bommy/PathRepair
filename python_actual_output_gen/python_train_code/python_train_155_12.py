t=int(input())
while(t):
  n=int(input())
  a=list(map(int,input().split()))
  if(n==1):
    print("0")
  else:
    c={}
    for x in range(n):
      if(a[x] in c):
        c[a[x]]+=1
      else:
        c[a[x]]=1
  print(len(c))
  t-=1