n, m = map(int, input().split())
l = [0] + [int(x) for x in input().split()] + [m]
b = [0]*(n+2)

for i in range(1,len(l)):
    if int(i) % 2 != 0:
        b[i] += b[i-1] + l[i] - l[i-1]
    else:
        b[i] = b[i-1]

ans = b[-1]

for i in range(1,n+2):
    if (l[i]-l[i-1]>1):
        if int(i) % 2 == 1:
            ans = max(ans, b[i]+m-l[i]-(b[n+1]-b[i])-1)
        else:
            ans = max(ans, b[i]+l[i]-l[i-1]-1+m-l[i]-(b[n+1]-b[i]))
    print(ans)