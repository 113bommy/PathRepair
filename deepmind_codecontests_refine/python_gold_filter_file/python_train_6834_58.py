loops = int(input())
eights = loops//2
six = loops %2
if loops > 36:
    print("-1")
else:
    for i in range(eights):
        print("8", end="")
    for i in range(six):
        print("6", end="")
