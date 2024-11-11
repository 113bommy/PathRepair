t=int(input())
for j in range(t):
    n=int(input())
    l=[]
    for g in range(n):
        o=input()
        l.append(o)
    d={}
    for i in l:
        for y in i:
            if y not in d:
                d[y]=1
            else:
                d[y]+=1
    
    if n%2==0:
        ret="YES"
        for p in d.values():
            if p%2!=0:
                ret="NO"
                break
        print(ret) 
    else:
        ret="YES"
        for p in d.values():
            if n%p!=0:
                ret="NO"
                break
        print(ret)