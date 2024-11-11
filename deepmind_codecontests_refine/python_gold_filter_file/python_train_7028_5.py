pieces = int(input())
order = list(map(int,input().split()))
first_1 = 0
consec = 1
ways = 1
exist_1 = 0
for i,piece in enumerate(order):
    if piece == 1:
        first_1 = i
        exist_1 = 1
        break
if exist_1 == 1:
    for piece in order[first_1:]:
        if piece == 1:
            ways *= consec
            consec = 1
        else:
            consec +=1
            
    print(ways)
else:
    print('0')