from math import factorial as f
n=int(input())
d=0
out=1
for i in range(n) :
    m=int(input())
    out=out*f(d+m-1)//f(d)//f(m-1)%1000000007
   
    d+=m
    
print(out)
