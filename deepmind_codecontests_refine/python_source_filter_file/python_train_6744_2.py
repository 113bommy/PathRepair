N=int(input())
A=list(map(int,input().split()))
ans=[]
for i in A:
    ans[i-1]+=1
for j in ans:
    print(j)