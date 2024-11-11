n,k,q = [int(i) for i in input().split()]
alist = [int(i) for i in input().split()]
blist = []
for i in range(q):
    a,b = [int(j) for j in input().split()]
    if a == 1:
        if len(blist) < k:
            blist.append(alist[b-1])
        else:
            if alist[b-1] > min(blist):
                blist.append(alist[b-1])
                blist.remove(min(blist))
    elif a == 2:
        if alist[b-1] in blist:
            print ('Yes')
        else:
            print ('No')