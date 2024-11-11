for i in range(int(input())):
    l=list(map(int,input().split()))
    l.sort()
    count=0
    if l.count(0)==1:
        l[2]-=1
        l[1]-=1
        count+=2
        if l[1]>0 and l[2]>0:
            count+=1
        print(count)
        continue
    if l.count(0)==2:
        print(1)
        continue
    if max(l)==1:
        print(l.count(1))
        continue
    if max(l)==0:
        print(0)
        continue
    if min(l)==4:
        print(7)
        continue
    if l[0]>0:
        l[0]-=1
        l[1]-=1
        l[2]-=1
        count+=3

    if l[0]>0 and l[1]>1:
        l[0]-=1
        l[1]-=1
        count+=1
    l.sort()
    if l[1]>0:
        if l[0]==0:
            count+=0
        else:
            l[0]-=1
            l[2]-=1
            count+=1
    l.sort()
    if l.count(0)==1:
        count+=1
    print(count)
        
            
            
        