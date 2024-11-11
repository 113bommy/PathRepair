n=int(input())
a=list(map(int,input().split()))
ans=[0]*n
for i in a:
    ans[i-1]+=1
for k in ans:
    print(k)

