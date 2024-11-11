a,b,n=map(int,input().strip().split(" "))
d="-1"
r=0
for i in range(1,10):
    r=a*10+i
    if r%b==0:
        d=str(r)+"0"*(n-1)
        break
print(d)
      
        