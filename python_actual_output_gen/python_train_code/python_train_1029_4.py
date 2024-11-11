n,m=map(int,input().split())
a=sorted(list(map(int,input().split())))
b=sorted(list(map(int,input().split())))
if max(a)<min(b):
    if min(a)*2<max(a) and min(a)*2<min(b):
        print(max(a))
    elif min(a)*2>max(a) and min(a)*2<min(b):
        print(min(a)*2)
    else:
        print(-1) 
else:
    print(-1)