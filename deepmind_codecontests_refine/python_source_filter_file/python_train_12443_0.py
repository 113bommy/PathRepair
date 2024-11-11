s, x = input().split()
s, x = int(s), int(x)

ones_in_x = 0
for let in reversed("{0:b}".format(x)):
    if let == "1":
        ones_in_x += 1

zbytkove = s - x

if zbytkove % 2 == 1:
    print(0)
elif s == x:
    print(2**ones_in_x - 2)
else:
    for zb, let in zip(reversed("{0:b}".format(zbytkove//2)), reversed("{0:b}".format(x))):
        if zb == "1" and zb == let:
            print(0)
            break
    else:
        print(2**ones_in_x)




