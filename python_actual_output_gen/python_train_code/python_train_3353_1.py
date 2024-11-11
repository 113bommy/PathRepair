def jorab(x, y , z):
    l=0
    l += x
    if (x+z)//y > 0:
        l+= jorab((x+z)//y, y,x%y )
    return l
x = [int(i) for i in list(input().split(" "))]
print (jorab(x[0], x[1], 0))