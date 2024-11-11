x, y = (max(4 - int(i), 0) or i in input().split())
print((x + y + 4*(x==y==3)) * 10**5)