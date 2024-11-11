n=int(input())
a=list(map(int,input().split()))

flag=0
for i in range(n):
    if(sum(a[i:n+i])!=sum(a[n+i:])+sum(a[:i])):

        flag=1

        break

if(flag==0):
    print(-1)
else:
    for j in range(i,2*n):
        print(a[j],end=" ")
    for k in range(i):
        print(a[k],end=" ")

