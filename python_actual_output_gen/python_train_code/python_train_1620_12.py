X, Y = map(int, input().split())

points = [-1, 100000, 200000, 300000, 0]
print(400000*(X==Y==1) + points[max(4, X)] + points[max(4, Y)])