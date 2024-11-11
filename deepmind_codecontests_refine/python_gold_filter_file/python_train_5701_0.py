from functools import reduce

def factorial(n):
    return reduce(lambda x, y: x*y, range(1,n+1))

colors = {
    'R' : 0,
    'O' : 0,
    'Y' : 0,
    'G' : 0,
    'B' : 0,
    'V' : 0
}

for c in list(input()):
    colors[c] += 1

amount = list(reversed(sorted([(colors[key], key) for key in colors])))

amount = [x[0] for x in amount]

if amount[0] == 6 or amount[0] == 5:
    print("1")
elif amount[0] == 4:
    print("2")
elif amount[0] == 3:
    if amount[1] == 3:
        print("2")
    elif amount[1] == 2:
        print("3")
    elif amount[1] == 1:
        print("5")
elif amount[0] == 2:
    if amount[1] == amount[2] == 2:
        print("6")
    elif amount[1] == 2:
        print("8")
    else:
        print(factorial(6) // 48)

elif amount[0] == 1:
    print(factorial(6) // 24)



