a,b,c=map(int,input().split())
n=int(input())
ans=0
for i in input().split():
        i=int(i)
        if i>b and i<c:
                ans=+1
print(ans)
