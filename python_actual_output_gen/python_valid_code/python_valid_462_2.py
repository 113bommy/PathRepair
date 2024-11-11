t = int(input())
for _ in range(t):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    notes = [10**x for x in a]
    s=0
    save=0
    last=False
    for i in range(len(a)):
        if(i==len(a)-1):
            temp=k
            last=True
        else:
            temp = min(k,notes[i+1]//notes[i]-1)
        s+=temp*notes[i]
        k-=temp
        save=i
        if(k==0):
            break
    if(last):
        print(s+notes[-1])
        continue
    if(temp<notes[save+1]/notes[save]):
        s+=notes[save]
    else:
        s+=notes[save+1]
    print(s)
        
        
