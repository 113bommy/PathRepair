def magic(x, y):
    if(x >= y):
        return("YES")
    elif(x == 1) or (x == 3):
        return("NO")
    elif(x == 2) and (y >= 3):
        return("NO")
    return("YES")    

for _ in range(int(input())):
    x, y = list(map(int, input().split()))
    print(magic(x,y))