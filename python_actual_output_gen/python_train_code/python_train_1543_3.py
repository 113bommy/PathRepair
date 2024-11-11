n = int(input())
genom = input()
A = n // 4 - genom.count("A")
B = n // 4 - genom.count("C")
G = n // 4 -  genom.count("G")
T = n // 4 -  genom.count("T")
if len(genom) % 4 != 0:
    print("===")
elif A < 0 or B < 0 or G < 0 or T < 0:
    print("===")
else:
    for i in genom:
        if i != "?":
            print(i, end="")
        else:
            if A > 0:
                print("A", end="")
                A -= 1
            elif B > 0:
                print("B", end="")
                B -= 1
            elif G > 0:
                print("G", end="")
                G -= 1
            elif T > 0:
                print("T", end="")
                T -= 1