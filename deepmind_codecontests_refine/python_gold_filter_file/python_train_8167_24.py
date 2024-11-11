n, t = [int(n) for n in input().split()]
cell = [int(cell) for cell in input().split()]

def check():
    m = 1
    while True:
        if m == t :
            return 'YES'
        if m > t:
            return 'NO'
        m = m + cell[m-1]

print(check())