current = input()
target = input()

mx = -ord(current[0]) + ord(target[0])
my = -int(current[1]) + int(target[1])

moves_total = abs(mx) + abs(my) - min(abs(mx), abs(my))

print(moves_total)

while mx != 0 and my != 0:
    if mx > 0 and my > 0:
        print("RU")
        mx -= 1
        my -= 1
    elif mx < 0 and my < 0:
        print("LD")
        mx += 1
        my += 1
    elif mx > 0 and my < 0:
        print("RD")
        mx -= 1
        my += 1
    else:
        print("RU")
        mx += 1
        my -= 1
if mx > 0:
    while mx:
        print("R")
        mx -= 1
elif mx < 0:
    while mx:
        print("L")
        mx += 1
elif my > 0:
    while my:
        print("U")
        my -= 1
elif my < 0:
    while my:
        print("D")
        my += 1
