import sys
f = sys.stdin


import string

OFFSET = ord('a')

def to_gamma(c):
    return ord(c) - OFFSET

def from_gamma(gamma, alpha, beta):
    return chr((alpha * gamma + beta) % 26 + OFFSET) 

def affine(c, alpha, beta):
    return from_gamma(to_gamma(c), alpha, beta)


# g[0]==g[3]である前提
def search_that(w):
    b = to_gamma(w[2])
    for a in range(26):
        if w[0] == affine('t',a,b) and w[1] == affine('h',a,b):
            return a, b
    return -1, -1

def search_this(g):
    a = (to_gamma(w[0]) - to_gamma(w[3]) + 26) % 26
    for b in range(26):
        if w[0] == affine('t',a,b) and w[1] == affine('h',a,b) and w[2] == affine('i',a,b) and w[3] == affine('s',a,b):
            return a, b
    return -1, -1

def search(w):
    if w[0] == w[3]:
        return search_that(w)
    else:
        return search_this(w)

n = int(f.readline())
for i in range(n):
    line = f.readline().strip()
    words = [word for word in line.split() if len(word) == 4]
    for word in words:
        a, b = search(word)
        if a != -1:
            print(line.translate(str.maketrans(''.join([affine(c, a, b) for c in string.ascii_lowercase]), string.ascii_lowercase)))
            break    
    