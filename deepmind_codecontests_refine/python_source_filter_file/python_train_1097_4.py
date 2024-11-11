i = 0
xt = 0
yt = 0
zt = 0

n = int(input())

while i < n:
    
    x, y, z = map(int, input().split())
    
    xt += x
    yt += y
    zt += z
    
    i += 1
    
if xt == 0 and yt == 0 and zt == 0:
    print("YES")
else:
    print("no")