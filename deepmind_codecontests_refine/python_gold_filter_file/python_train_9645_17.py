n=int(input())
a=list(map(int,input().split()))
b=set(a)
if 0 not in a:
    print(len(b))
else:
    c=0
    for i in b:
        if i>0:
            c+=1
    print(c)