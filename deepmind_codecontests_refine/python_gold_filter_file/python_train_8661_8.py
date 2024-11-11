n = int(input())

for j in range(n):
    dig = [int(x) for x in input()]
    l = len(dig)
    sum= 0
    b = False
    c= False

    for i in dig:
        if not(b) and i == 0: b = True
        elif not c and i % 2 == 0: c = True
        sum += i

    if (b and c and sum % 3 == 0): print("red")
    else: print("cyan")
