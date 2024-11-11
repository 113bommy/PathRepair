#ar = list(map(int, input().strip().split(' ')))

t=int(input())
for i in range(t):
    n=int(input())
    l=[]
    
    c=0
    for j in range(n):
        li,ri = map(int, input().strip().split(' '))
        if j==0:
            if li<ri:
                l.append(li)
                c+=li
            else:
                l.append(0)
                c=0
        else:
            if ri<=c:
                l.append(0)
            else:
                c=max(c+1,li)
                l.append(c)
    for j in range(n):  
        print(l[j],end=" ")
    print()
        
    
