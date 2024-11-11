t=int(input())
while t!=0:
    lst=[]
    count=0
    n=int(input())
    s=input()
    for i in range(n):
        if s[i]=='(':
          lst.append(-1)
        else:
            lst.append(1)
    res=0
    i=0
    while i<n:
        res+=lst[i]
        if res<0:
            lst.append(lst[i])
            lst.pop(i)
            count+=1
            i-=1
            res=0
        i+=1
    print(count)
    t-=1
            
                