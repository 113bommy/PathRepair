a=int(input())
b=list(map(int,input().split()))
c=int(input())
d=list(map(int,input().split()))
e=0
for i in range(a):
    for j in range(c):
        e=0
        e=b[i]+d[j]
        if e not in b and e not in d:
            print(b[i],d[j])
            e=1
            break
    if(e==1):
        break
        