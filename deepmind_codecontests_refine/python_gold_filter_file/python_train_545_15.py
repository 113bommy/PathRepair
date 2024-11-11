n = int(input())
l = list(map(int,input().split()))
print(1,1)
print(-l[0])
if n==1:
    for i in range(2):
        print(1,1)
        print(0)
else:
    v1,v2=[],[0]
    for i in range(1,n):
        v1.append((l[i]%n)*(n-1))
        l[i]+=v1[-1]
        v2.append(-l[i])
    print(2,n)
    print(*v1)
    print(1,n)
    print(*v2)