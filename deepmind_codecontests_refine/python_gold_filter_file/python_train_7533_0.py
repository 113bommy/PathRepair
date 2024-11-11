import sys

def fail():
    print('IMPOSSIBLE')
    sys.exit()

n, m, a, b, c = map(int, input().split())
if (n * m) % 2 == 1:  # odd area
    fail()
if n * m > 2 * (a + b + 2 * c):  # too large
    fail()
g = [ [ ' ' for c in range(m) ] for r in range(n) ]

if n % 2 == 1:
    if m > 2 * a:  # not enough horizontal planks
        fail()
    letter = 'y'
    for i in range(0, m, 2):
        g[n - 1][i] = g[n - 1][i + 1] = letter
        letter = 'z' if letter == 'y' else 'y'
    a -= m // 2

if m % 2 == 1:
    if n > 2 * b:  # not enough vertical planks
        fail()
    letter = 'y'
    for r in range(0, n, 2):
        g[r][m - 1] = g[r + 1][m - 1] = letter
        letter = 'z' if letter == 'y' else 'y'
    b -= n // 2
        
a -= a % 2  # get rid of odd pieces
b -= b % 2
if (n - n % 2) * (m - m % 2) > 2 * (a + b + 2 * c):  # remainder too large
    fail()
letter_pairs = ( ('a', 'i'), ('x', 'q') )
for r in range(0, n - n % 2, 2):
    for c in range(0, m - m % 2, 2):
        letters = letter_pairs[(r // 2 + c // 2) % 2]
        if a > 0:
            g[r][c] = g[r][c + 1] = letters[0]
            g[r + 1][c] = g[r + 1][c + 1] = letters[1]
            a -= 2
        elif b > 0:
            g[r][c] = g[r + 1][c] = letters[0]
            g[r][c + 1] = g[r + 1][c + 1] = letters[1]
            b -= 2
        else:
            g[r][c] = g[r + 1][c] = g[r][c + 1] = g[r + 1][c + 1] = letters[0]
            c -= 1

print('\n'.join([ ''.join(g[r]) for r in range(n) ]))
