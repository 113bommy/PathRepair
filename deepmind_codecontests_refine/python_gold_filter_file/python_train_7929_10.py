n=int(input())
a=list(map(int,input().split()))
m=int(input())
b=list(map(int,input().split()))
flag=True
for i in range(n):
    for j in range(m):
        s=a[i]+b[j]
        if s in a or s in b:
            continue 
        else:
            flag=False
            print(a[i],b[j])
            break
    if flag == False:
        break