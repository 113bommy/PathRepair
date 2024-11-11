a,b,c=map(int,input().split())
min_s=min(a,b,c)
max_s=min(a,b,c)
if(min_s+(a+b+c-min_s-max_s)<max_s):
    print(2*max_s+1-(a+b+c))
else:
    print(0)