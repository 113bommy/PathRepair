d = {
    "q": 9,
    "r": 5,
    "b": 3,
    "k": 3,
    "p": 1
}

def type_value(i):
    if i.lower() not in d:
        return 0
    return d[i.lower()]

w = 0
b = 0

for _ in range(8):
    p = list(input())
    for piece in p:
        if piece.isupper():
            w += type_value(piece)
        elif piece.islower():
            b += type_value(piece)


if w > b:
    print("White")
elif w < b:
    print("Black")
else:
    print("Draw")