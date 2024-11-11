n=int(input());l,r=1,0;d={};i=0
while i<n:
    a=input().split(); x=a[0];y=a[1]
    if x=='L': l-=1;d[y]=l
    elif x=='R': r+=1;d[y]=r
    else: print(min(d[y]-l,r-d[y]))
    i+=1