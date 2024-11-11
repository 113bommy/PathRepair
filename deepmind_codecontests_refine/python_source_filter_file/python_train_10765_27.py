r = [
    "O-|-OOOO",
    "O-|O-OOO",
    "O-|OO-OO",
    "O-|OOO-O",
    "O-|OOOO-",

    "-O|OOOO",
    "-O|O-OOO",
    "-O|OO-OO",
    "-O|OOO-O",
    "-O|OOOO",
]

n = input()
n = str(n)
for d in reversed(n):
    d = int(d)
    print(r[d])
