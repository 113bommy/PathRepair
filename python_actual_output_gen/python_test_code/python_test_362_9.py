n=int(input())
k=int(input())
a=list(map(int,input().split()))
ans = 0
for i in a:
    ans+=min(a*2,abs(k-a)*2)
print(ans)