for _ in range(int(input())):
    s=input()
    a=[]
    l=0
    for char in s:
        if(char and 1):
            l+=1
        else:
            a.append(l)
            l=0
    a.append(l)
    a.sort()
    t=0
    n=len(a)
    for i in range(n-1,-1,-2):
        t+=a[i]
    print(t)