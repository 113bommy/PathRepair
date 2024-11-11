l=list(map(int,input().split()))
y=l[0]
b=l[1]
r=l[2]
while True:
     if r-1>b:
          r-=1
     else:
          b=r-1
          if b-1>r:
               b-=1
               r-=1
          else:
               y=b-1
               break
print(r+y+b)
