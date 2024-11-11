N=int(input())
s=[]
for i in range(N):
    s.append(int(input()))
a=[0]
ans=sum(s)
if ans%10==0:
    for i in s:
        if (ans-i)%10 != 0:
            a.append(ans-i)
    ans=max(a)
print(ans)