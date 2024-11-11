n=int(input())
num=[int(x) for x in list(input())]
f=[int(x) for x in input().split()]
flag=0
for i in range(n):
    if num[i]<f[num[i]-1]:
        num[i]=f[num[i]-1]
        flag=1
    elif num[i]==f[num[i]-1]:
        if flag==1:
            break
print(*num,sep='')
