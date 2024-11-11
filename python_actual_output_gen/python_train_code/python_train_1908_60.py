n,m,k=map(int,input().split())
ans=['Yes','No']
i=1
for a in range(n+1):
    for b in range(m+1):
        if k==a*m+b*n-a*b:
            i=0
print(ans[i])