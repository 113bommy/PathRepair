reps = input()

def xor(a,b):
    return "1" if a != b else "0"

for i in range(int(reps)):

    b1, b2 = input().split(" ")
    b1 = list(bin(int(b1)).replace("0b",""))
    if len(b1) < 16:
        dif = 16 - len(b1) 
        b1 = list(str(0)*dif) + b1
    b2 = list(bin(int(b2)).replace("0b",""))
    if len(b2) < 16:
        dif2 = 16 - len(b2) 
        b2 = list(str(0)*dif2) + b2
    binRep = "".join(map(xor,b1,b2))
    print(int(binRep,2))