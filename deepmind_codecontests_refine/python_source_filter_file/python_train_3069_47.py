whites = {"Q":9, "R":5, "B":3, "K":3, "P":1}
blacks = {"q":-9, "r":-5, "b":-3, "k":-3, "p":-1}
white_value = 0
black_value = 0
n = []
for i in range(8):
    n += [list(input().split())]
    for j in n[-1]: # why does it take the whole n[-1], when I wanted to iter 
        for q in j:
            if q in whites:
                white_value += whites[q] 
            elif q in blacks:
                black_value += abs(blacks[q])

if white_value > black_value:
    print("White")
elif white_value == black_value:
    print("Draw")
else:
    print("Black")
