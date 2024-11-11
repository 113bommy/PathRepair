ALFANUM = {
    'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6,
    'h': 7, 'i': 8, 'j': 9, 'k': 10,'l': 11,'m': 12,'n': 13,
    'o': 14,'p': 15,'q': 16,'r': 17,'s': 18,'t': 19,'u': 20,
    'v': 21,'w': 22,'x': 23,'y': 24,'z': 25
}

EXEPT = 'az'

def process():
    sLen = int(input())
    mid = int(sLen / 2)
    last = sLen - 1
    s = input()
    for i in range(mid):
        ltL = s[i]
        ltR = s[last - i]
        print("letras {} - {}".format(ltL, ltR))
        if ((ltL in EXEPT) and (ltR == ltL)): 
            continue
        nsL = ALFANUM[ltL]
        nsR = ALFANUM[ltR]
        diff = abs(nsL - nsR) 
        print("numero |{} - {}| = {}".format(nsL, nsR, diff))
        if diff > 2 or diff == 1: return 'NO'
    return 'YES'
        
def run():
    T = int(input())
    for _ in range(T):
        print(process())

run()