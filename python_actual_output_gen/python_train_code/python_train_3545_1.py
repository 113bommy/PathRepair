n=int(input())
a=[[0,0]]
for i in range(n):
    a.append(list(map(int,input().split())))
ans=[]
i=1
while len(ans)<n:
    if a[i][1] in a[ a[i][0] ] and a[i][1]!=1:
        ans.append(a[i][1])
        i=a[i][1]
    else:
        ans.append(a[i][0])
        i=a[i][0]
print(*ans)
        
