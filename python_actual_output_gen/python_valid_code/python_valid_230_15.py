n,x,y=map(int,input().split())
l=[int(n) for n in input().split()]
l=sorted(l)
print(l)
if x>y:
    print(n)
elif x<=y:
    index=-1
    for i in l:
        if i<=x:
            index+=1
    l=l[:index+1]
    print(len(l)-len(l)//2)