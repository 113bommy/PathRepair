n  = int(input())
listt = []
sumx ,sumy,sumz = 0,0,0
while n:
    x,y,z = map(int,input().split())
    sumx+=x
    sumy+=y
    sumz+=z
    n-=1
if sumx==sumy==sumz:
    print("YES")
else:
    print("NO")