q = int(input())
for i in range(q):
    n,m,k = map(int,input().split())
    mx = max(n,m)
    if(mx>k):
        print(-1)
        continue
    ab = abs(n-m)
    if(ab%2==0):
        if((k-mx)%2==0):
            print(k)
        else:
            print(k-2)
    else:
        print(k-1)