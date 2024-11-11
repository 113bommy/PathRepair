t=int(input())
for _ in range(t):
    l,r=map(int,input().split())
    c=0
    while(l>0 or r>0):
      c+=(r-l)
      r=r//10
      l=l//10
    print(c)