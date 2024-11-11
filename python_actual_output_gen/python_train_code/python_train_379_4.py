n = int(input())
r = sorted(list(map(int, input().split())), reverse = True)

area = 0
if n%2 == 0:
    for i in range(0,n,2):
        area += 3.1415926536*(r[i]**2 - r[i+1]**2)
    print(area)

else:
    area = 3.1415926536*r[n-1]
    for i in range(0,n-2,2):
        area += 3.1415926536*(r[i]**2 - r[i+1]**2)
    print(area)
