import sys

input=sys.stdin.readline

for _ in range(int(input())):
    n,m=map(int,input().split())
    a=[]
    for i in range(n):
        a.append(input())

    for i in range(m):
        ans=[""]*m
        for j in range(m):
            if j!=i:
                ans[j]=a[0][j]
        flag=True
        for j in range(1,n):
            check=0
            for k in range(m):
                if ans[i]=="":
                    if ans[k]!=a[j][k] and k!=i:
                        check+=1
                else:
                    if ans[k]!=a[j][k]:
                        check+=1
            if ans[i]=="":
                if check>1:
                    flag=False
                elif check==1:
                    ans[i]=a[j][i]
            else:
                if check>0:
                    flag=False
        if flag:
            if ans[i]=="":
                ans[i]="a"
                print("".join(ans))
            else:
                print("".join(ans))
            break
    else:
        print(-1)