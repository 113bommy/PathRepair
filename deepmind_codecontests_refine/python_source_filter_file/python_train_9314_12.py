N,x,y = list(map(int,input().split()))
uniq = set()

for i in range(N):
    x1,y1 = map(int,input().split())
    if x-x1 == 0 and y - y1 != 0:
        uniq.add(x1)
    elif y-y1 == 0 and x - x1 != 0:
            uniq.add(y1)
    else:

        uniq.add(((y-y1)/(x-x1),y - (y-y1)/(x-x1)*x))

print(len(uniq))