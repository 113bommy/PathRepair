a,b=map(int,input().split())
n=max(a,b)
if(max(a,b)-min(a,b)>1):
    print(min(a,b),(n-min(a,b))//2)
else:
    print(a,0)
