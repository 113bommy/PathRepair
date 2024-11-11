a=input().split()
z=int(a[0])+int(a[1])+int(a[2])+int(a[3])+int(a[4])
if z%5>0:
    print(-1)
else:
    print(z//5)
