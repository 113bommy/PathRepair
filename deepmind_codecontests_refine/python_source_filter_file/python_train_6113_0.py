n,m=map(int,input().split())
a=list(map(int,input().split()))
p=list(map(int,input().split()))
for i in p:
    if i in a:
        print(i)