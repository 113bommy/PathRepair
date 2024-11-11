from collections import defaultdict
def fun():
    return 0
n=int(input())
arr=[int(x) for x in input().split()]
arr=sorted(arr)
d=defaultdict(fun)
flag=True
for i in arr:
    d[i]+=1
    if d[i]>2:
        flag=False
        break
if not flag:
    print("NO")
else:
    print("YES")
    dec=[]
    dd=0
    arr=list(set(arr))
    for i in arr:
        if d[i]==2:
            dd+=1
            dec.append(i)
    
    print(dd)
    if dd==0:
        print()
    else:
        for i in dec:
            print(i,end=" ")
        print()

    a=len(arr)
    print(a)
    if a==0:
        print()
    else:
        for i in arr[::-1]:
            print(i,end=" ")
        print()

