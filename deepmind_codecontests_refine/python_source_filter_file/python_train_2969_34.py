inp = input().split(" ")
inp[0] = int(inp[0])
if inp[-1] == "month":
    if inp[0] <= 29:
        print(12)
    else:
        if inp[0] == 30:
            print(11)
        else:
            print(7)
else:
    if inp[0] == 5 or inp[0] == 6:
        print(52)
    else:
        print(51)