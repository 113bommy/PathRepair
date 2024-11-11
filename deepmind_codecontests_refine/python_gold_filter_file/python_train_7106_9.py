def go(res):
    cur=0
    for i in range(n):
        for j in range(m):
            f=a[i]&b[j]
            if res|f==res:cur|=f;break
        else:return False
    return cur==res
n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
for i in range(1<<9):
    if go(i):exit(print(i))