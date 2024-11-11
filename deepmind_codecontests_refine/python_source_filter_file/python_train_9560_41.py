a,b=map(int,input().split())
cnt=0
for i in range(a,b):
    j=str(i)
    if j==j[::-1]:
        cnt+=1
print(cnt)