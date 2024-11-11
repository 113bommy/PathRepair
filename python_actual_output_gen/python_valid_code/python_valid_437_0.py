t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    li=[]
    for i in range(m):
        a,b,c=map(int,input().split())
        li.append(b)
    li.sort()
    di=dict()
    for i in range(m):
        di[li[i]]=1
    num=0
    for i in range(1,n+1):
        if i not in di:
            num=1
            break
    for i in range(1,n+1):
        if i!=num:
            print(num,i)