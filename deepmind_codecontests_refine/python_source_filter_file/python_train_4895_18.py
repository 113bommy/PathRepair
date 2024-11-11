minv = -1000000000
maxv = 1000000000

for _ in range(int(input())) :
    num	= int(input())
    maxv = max(maxv,num	- minv)
    minv = min(minv,num)
print(maxv)

