n,m=map(int,input().split())
l=[]
v=1
for i in range(m) :
    a=int(input())
    if a%n in l :
        print(v)
        exit()
        break
    else :
        l.append(a%n)
        v=v+1
print(-1)

    
