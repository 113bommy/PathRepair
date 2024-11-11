for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    s=[]
    for i in range(n):
        for j in range(n-2):
            if(l[j]>l[j+1]):
                l[j],l[j+2]=l[j+2],l[j]
                l[i],l[j+1]=l[j+1],l[j]
                s.append(j+1)
                s.append(j+1)
            elif(l[j+1]>l[j+2]):
                l[j],l[j+2]=l[j+2],l[j]
                l[i],l[j+1]=l[j+1],l[j]
                s.append(j+1)
    if(l!=sorted(l)):
        print(-1)
    else:
        print(len(s))
        print(*s)
                
                
