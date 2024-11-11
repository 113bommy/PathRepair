NN = 19
X = [0] * ((1<<NN+1)-1)
 
def popcount(x):
    x -= (x >> 1) & 0x55555555
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
    x = (x + (x >> 4)) & 0x0f0f0f0f
    x += x >> 8
    x += x >> 16
    return x & 0x3f

def update(a, x):
    i = (1<<NN) - 1 + a
    X[i] = x
    while True:
        i = (i-1) // 2
        X[i] = X[2*i+1] | X[2*i+2]
        if i == 0:
            break

def rangeor(a, b):
    l = a + (1<<NN)
    r = b + (1<<NN)
    x = 0
    while l < r:
        if l%2:
            x |= X[l-1]
            l += 1
        if r%2:
            r -= 1
            x |= X[r-1]
        l >>= 1
        r >>= 1
    return x

N = int(input())
A = [ord(a) - 97 for a in input()]
for i, a in enumerate(A):
    update(i+1, 1<<a)

Q = int(input())
for _ in range(Q):
    a, b, c = input().rstrip().split()
    if a == "1":
        b = int(b)
        c = ord(c) - 97
        update(b, 1<<c)
    else:
        b, c = int(b), int(c)
        print(popcount(rangeor(b, c+1)))