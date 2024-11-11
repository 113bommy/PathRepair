t=int(input())
for i in range(t):
    #n=int(input())    
    a,b,c,n=map(int,input().split())
    #l=list(map(int,input().split()))
    l=[]
    l.append(a)
    l.append(b)
    l.append(c)
    l.sort()
    c=n-(l[2]-l[0]+l[2]-l[1])
    if c>=0 and c%3==0:
        print("YES")
    elif a==b and a==c and n%3==0:
        print("YES")
    else:
        print("NO")