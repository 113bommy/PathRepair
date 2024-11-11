input()
a=list(map(int,input().split()))
v=list(map(int,input().split()))
for i in a:
    if a in v:
        print(a,end="")
    