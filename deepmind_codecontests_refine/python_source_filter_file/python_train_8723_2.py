n=int(input())
a=list(map(int,input().split()))
a0=sum(a)//2-sum(a[1::2])
ans=[a0*2]
for i in range(n-2):
    ans.append(a[i]*2-ans[-1])
ans.append((a[-1]-a0)*2)
print(ans)
