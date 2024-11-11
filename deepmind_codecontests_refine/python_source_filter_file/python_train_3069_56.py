board = [input() for i in range(8)]
all_pieces = []

for row in board :
    for coin in row  :
        all_pieces.append(coin)

Black_weight = {'q' :9, 'r':5, 'b':3, 'k':3, 'p':1}
White_weight = {'Q' :9, 'R':5, 'B':3, 'K':3, 'P':1}

def totalWeight(color, all_pieces) :
    weight = 0
    for i in color.keys() :
        weight += (all_pieces.count(i) * color[i])
    return weight

Black, White = totalWeight(Black_weight, all_pieces) , totalWeight(White_weight, all_pieces)

if Black > White :
    print("Black")
elif Black < White :
    print("White")
else:
    print("Draw")