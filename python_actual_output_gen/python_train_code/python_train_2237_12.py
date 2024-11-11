presents, boxes = map(int, input().split())
print( pow(pow(2, boxes, 10**9+1) - 1, presents, 10**9+1) )