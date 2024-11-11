x = input()
y = int(x[0:2].replace(" ",""))


if x.find("month") != -1:
    if y == 31:
        print(7)
    elif y == 30:
        print(11)
    elif y<=29:
        print(12)
elif y==5:
    print(53)
else:
    print(52)