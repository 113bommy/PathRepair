d=input().split(' ')
n=int(d[1])
lenc=int(d[0])
d=list(map(lambda x:int(x),input().split(' ')))
if sum(d)+lenc-1==n:
    print("YES")
else:
    print("NO")