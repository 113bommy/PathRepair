
target = input()

codes = [ord(x) for x in target]

def letter(code: int):
    line1 = '.' + 'X'*code + '.'
    line2 = 'X' * (code+2)
    return [line1, line2]

def printer(code: int):
    """ -2, print, -code"""
    lines = ['.X.X']
    line2 = 'XX.' + 'X.'*(code-1)
    line3 = '.'*(code*2 - 1) + 'XX'
    return lines + [line2, line3]

def one(code):
    r = []
    r.extend(letter(code))
    r.append('.')
    r.extend(printer(code))
    r.append('.')
    r.append('.')
    return r
    
def all(codes):
    r = []
    for code in codes:
        r.extend(one(code))
    maxlen = max(len(x) for x in r) + 3
    for line in r:
        print(line + '.'*(maxlen - len(line)))


# one(codes[0])
all(codes)
