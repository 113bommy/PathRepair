a,b = map(int, input().split())
ans = 0
while b > 1 and a > 0:
    b-=2
    a+=1
    a,b = sorted([a,b])
    ans+=1
print(ans)
