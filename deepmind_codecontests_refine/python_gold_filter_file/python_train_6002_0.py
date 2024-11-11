from sys import stdin,stdout
n,m=map(int,stdin.readline().split())
s=int((n*(n+1))/2)
r=m%s
k=r
#stdout.write(r)
i=1
while(True):
    if((r-i)<0):
        stdout.write(str(r))
        break
    else:
        r=r-i
        i=i+1
    
