t=int(input())
for q in range(t):
    pr1=-1
    pr2=-1
    e=1
    n=int(input())
    for i in range(n):
        l,r=map(int,input().split())
        if i==0:
            pr1=l
            pr2=r
            if r>l:
                e=0
        else:
            if r>l or l-r<pr2-pr1 or l<pr1 or r<pr2:
                e=0
        pr1=l
        pr2=r
    if not e:
        print("NO")
    else:
        print("YES")
