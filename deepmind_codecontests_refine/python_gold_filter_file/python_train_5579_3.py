n,m=map(int,input().split())
for i in range(m):
    q=0
    l=list(map(int,input().split()))
    l=set(l[1:])
    for e in l:
        if -e not in l:
            continue 
        else:
            q+=1
    if q==0:
        print("YES")
        exit()
print ("NO")