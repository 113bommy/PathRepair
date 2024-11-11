n=int(input())
r=list(set(list(map(int,input().split()))))

r.sort()

if len(r)==1:
    print(-1)
else:
    print(r[1])