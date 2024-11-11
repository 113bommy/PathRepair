a=[int(x) for x in input().split(" ")]
b=2*(a[1]+a[3])+a[0]+a[2]+abs(a[0]-a[2])
print(b)