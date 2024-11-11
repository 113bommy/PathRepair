a=int(input())
b=list(map(int,input().split()))
c=1
d=0
e=0
for i in range(1,a):
    f=b[i]-b[i-1]
    if(f!=0):
        if(f==d):
            g=e+1
        e=i-1
        d=f
    c=max(c,i-f+1)
print(c)