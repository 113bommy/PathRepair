n , x0, y0 = map(int,input().split())
inf = 1000000000
slopes = []

for i in range(n):
    x,y = map(int,input().split())
    if(x==x0):
        slopes.append(inf)
    else:
        slopes.append(abs((y-y0)/(x-x0)))

print(len(set(slopes)))