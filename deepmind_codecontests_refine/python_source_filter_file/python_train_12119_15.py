n=int(input())
*a,=map(int,input().split())
c=0
sw=0
for i in range(n):
    if i==a[i]:
        c+=1
    elif i==a[a[i]]:
        sw=1
print([c+2*sw,c+1][sw==0])