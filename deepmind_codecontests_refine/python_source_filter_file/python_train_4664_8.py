x,y = map(int,input().split())
a = [0]*210
a[:3] = [300000, 200000, 100000]
if x == y and x == 1:
    print(400000)
else:
    print(a[x-1] + a[y-1])
