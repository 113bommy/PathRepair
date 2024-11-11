n=int(input())
c=[list(map(int,input().split())) for _ in range(n)]
res=0
for i in range(n):
    s=[0]*4
    for j in range(n):
        if i==j:
            continue
        if c[i][0]==c[j][0]:
            if c[i][1]<c[j][1]:s[0]=1
            else:s[2]=1
        if c[i][1]==c[j][1]:
            if c[i][0]<c[j][0]:s[1]=1
            else:s[3]=1
    if sum(s)==4:res+=1
print(res)