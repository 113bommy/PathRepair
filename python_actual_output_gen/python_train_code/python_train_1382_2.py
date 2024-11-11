a1,a2 = map(int,input().split())
r = 0
while a1 > 1 or a2 > 1:
    if a1 >= a2:
        a1 -= 2
        a2 += 1
    else:
        a2 -= 2
        a1 += 1
    r += 1
print(r-1)
