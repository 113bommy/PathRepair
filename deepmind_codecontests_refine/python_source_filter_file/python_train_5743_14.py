def che(z):
    for i in range(a):
        for j in range(1,b):
            if z[i][j]<=z[i][j-1]:return False
    for i in range(1,a):
        for j in range(b):
            if z[i][j]<=z[i-1][j]:return False
    return True
a,b=map(int,input().split())
z=[list(map(int,input().split())) for _ in " "*a]
z1=[list(map(int,input().split())) for _ in " "*a]
for i in range(a):
    for j in range(b):
        z[i][j],z1[i][j]=min(z[i][j],z1[i][j]),max(z1[i][j],z[i][j])
if che(z) and che(z1):print("Posible")
else:print("Impossible")