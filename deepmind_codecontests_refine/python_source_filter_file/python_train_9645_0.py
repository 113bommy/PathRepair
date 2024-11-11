n=int(input())
a=list(map(int,input().split()))
if 0 in a:
    y=a.count(0)
    for k in range(y):
        a.remove(0)
if len(set(a))!=1:
    print(len(a))
else:
    print(1)
    
