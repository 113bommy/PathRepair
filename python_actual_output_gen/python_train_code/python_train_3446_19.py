def co(l,n):
    count=0
    for x in l:
        if x>=1 and x<n:
            #print(x,n)
            pre=count
            #print(pre)
            count+=1
            #print(count)
            
            if count>=n:
                return pre
    return count
for _ in range(int(input())):
    n=int(input())
    l=sorted(list(map(int,input().split())))
    k=l[-2]-1
    s=co(l[:-2],l[-2])
    print(s)