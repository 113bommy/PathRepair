t = int(input())
c = []
while t:
    n, k = map(int, input().split())
    cnt = 0
    while n:
        if n == 1:
            cnt+=1
            n-=1
        else:
            if n%k:
                cnt+=n%k
                n-=n%k
            else:
                cnt+=1
                n=n//k
    c.append(cnt)
    t-=1
for i in c:
    print(int(i))