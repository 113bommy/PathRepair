def prod(plop) :  
    thing = 1
    for x in plop: 
         thing = thing * x  
    return thing 

t = int(input())
for _ in range(t):
    n = int(input())
    l1 = [int(x) for x in input().split()]
    ans=[]
    for i in range(4):
        if i ==0:
            pos = sorted([x for x in l1 if x > 0])
            neg = sorted([x for x in l1 if x < 0])
        elif i==1:
            pos.reverse()
        elif i==2:
            neg.reverse()
        else:
            pos.reverse()

        for i in range(0,6):
            pos_seg = pos[:i]
            j = 5-i
            neg_seg = neg[:j]
            if len(pos_seg) + len(neg_seg)==5:
                ans.append(prod(pos_seg)*prod(neg_seg))
            else:
                if len(neg_seg)==5:
                    ans.append(prod(neg_seg))
                elif len(pos_seg)==5:
                    ans.append(prod(pos_seg))
    if 0 in l1:
        ans.append(0)

    print(max(ans))

    