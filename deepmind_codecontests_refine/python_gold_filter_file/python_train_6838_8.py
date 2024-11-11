n,k=map(int,input().split())
l=list(map(int,input().split()))
x=set(l)
p=[]
if(len(x)<k):
    print("NO")
else:
    print("YES")
    for i in range(len(l)):
        if(l[i] not in p)and len(p)<k:
            print(i+1,end=" ")
            p.append(l[i])
print("")