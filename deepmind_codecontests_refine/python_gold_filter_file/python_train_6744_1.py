n=int(input())
l=list(map(int,input().split()))

ans=[0]*n

for i in l:
    ans[i-1]+=1

for j in ans:
    print(j)