def chunks(l, n):
    for i in range(0, len(l), n):
        yield l[i:i+n]


stone = '[]'
scissors = '8<'
paper = '()'


def compare_r1_to_r2(r1, r2):
    if r1 == r2:
        return None
    elif r1 == stone and r2 == scissors or \
            r1 == paper and r2 == stone or \
            r1 == scissors and r2 == paper:
        return True
    else:
        return False


FT = input()
ST = input()

FT = list(chunks(FT, 2))
ST = list(chunks(ST, 2))

SFT, SST = 0, 0
for i in range(0, len(FT)):
    result = compare_r1_to_r2(FT[i], ST[i])
    if result:
        SST += 1
    elif result is not None:
        SFT += 1

if SFT > SST:
    print('TEAM 1 WINS')
elif SFT < SST:
    print('TEAM 2 WINS')
else:
    print('TIE')
