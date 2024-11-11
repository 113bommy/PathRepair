y = int(input())

while y <= 9000:
    y += 1
    ys = str(y)
    if ys[0] != ys[1] and ys[0] != ys[2] and ys[0] != ys[3] and ys[1] != ys[2] and ys[1] != ys[3] and ys[2] != ys[3]:
        break

print(y)
    
    
    
