def distinct(y):
    for i in y:
        if len(set(y)) == len(y):
            return 1
        else:
            return 0

y = int(input())
k = y
while k>=y: 
    l = distinct(str(k))
    if l == 1:
        print(str(k))
        break
    elif l == 0:
        k += 1