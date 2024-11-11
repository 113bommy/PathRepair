n, d = [int(i) for i in input().split()]
m = int(input())
rjes = []
for i in range(m):
    x, y = [int(i) for i in input().split()]
    # pravci
    # y = -x + d
    # y = x + d
    # y = x - d
    # y = -x - d
    #print(y, -x +d)
    #print(y, x + d)
    #print(y, x - d)
    #print(y, -x -d)
    if y >= -x + d and y <= x + d and y >= x - d and y <= -x - d + 2*n:
        
        rjes.append("YES")
    else:
        rjes.append("NO")

for i in rjes:
    print(i)
