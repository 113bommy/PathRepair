a, b = map(int, input().split())
if a == 0 or b == 0:
    if a + b == 1:
        print ("YES")
    else:
        print ("NO")
else:
    if abs(a-b) <= 2:
        print ("YES")
    else:
        print ("NO")