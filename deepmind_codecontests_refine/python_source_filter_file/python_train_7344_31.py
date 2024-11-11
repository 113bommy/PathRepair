n, b, d = map(int, input().split())
oranges = list(map(int, input().split()))


waste = 0
throws = 0
for o in oranges:
    if o > b:
        continue
    waste+=o
    if waste > d:
        waste-=d
        throws+=1
        
print(throws)