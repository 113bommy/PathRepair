r,g,b,n=map(int,input().split())
cnt=0
for i in range(n//r+1):
    for j in range(n//g+1):
        bc=n-(r*i+g*j)
        if bc%b==0 and bc>=0:
            cnt+=1
print(cnt)