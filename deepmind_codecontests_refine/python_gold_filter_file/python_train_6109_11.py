input()
a=list(map(int,input().split()))
v=list(map(int,input().split()))
for i in a:
    if i in v:
        print(i,end=" ")