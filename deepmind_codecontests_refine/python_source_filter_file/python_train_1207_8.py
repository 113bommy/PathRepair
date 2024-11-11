n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
a.sort()
ans = 0
for x in a:
    if(x > (k * 2)):
        while(x > (k * 2) ):
            k*=2
            ans+=1
        k = max(k*2,x*2)
print(ans)
