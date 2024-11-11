n,m=map(int,input().split())
a=[]
for i in range(n):
    a.append([])
    a[i].append([i,i])
c=n
for i in range(m):
    c1,c2=map(int,input().split())
    a[c1-1].append([c1-1,c])
    a[c2-1].append([c2-1,c])
    c+=1
for z in a:
    print(len(z))
    for t in z:
        print(t[0]+1,t[1]+1)
