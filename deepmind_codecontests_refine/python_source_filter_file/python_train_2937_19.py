m,n=map(int,input().split())
if m==1 and n==1:
    print(0)
    exit(0)
if n==1:
    for i in range(m):
        print(i+2)
    exit(0)
l=[[j+1 for i in range(n)] for j in range(m)]
print(l)
for i in range(n):
    for list in l:
        list[i]*=(m+1+i)
for i in l:
    print(*i)