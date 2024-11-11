x1, y1, x2, y2 = [int(x) for x in input().split()]
print((y2-y1+1)*(x2-x1)//2+(y2-y1)//2+x1%2)