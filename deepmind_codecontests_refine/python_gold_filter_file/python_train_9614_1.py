import bisect
n=int(input())
a=list(map(int,input().split()))
s=0
b=list(map(int,input().split()))
ans=[0]*5
for j in a:
    s+=j
    for i in range(4,-1,-1):
        if s>=b[i]:
            temp=s//b[i]
            ans[i]+=temp
            s=s%b[i]
print(*ans)
print(s)