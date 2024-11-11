a = [int(i) for i in input().split()]
triangles = min(a[1],a[3])*(2*a[2] + min(a[1], a[3])) + 2*abs(a[3] - a[1])*(a[2] + min(a[1], a[3])) + min(a[0], a[4])*(2*a[5] + min(a[0], a[4]))
print(triangles)
