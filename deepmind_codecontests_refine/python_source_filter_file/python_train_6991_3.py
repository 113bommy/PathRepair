from sys import maxsize, stdout, stdin
mod = int(1e9 + 7)
def I(): return int(stdin.readline())
def lint(): return [int(x) for x in stdin.readline().split()]
def S(): return input().strip()
def grid(r, c): return [lint() for i in range(r)]
x,y,z= map(int,S().split())
if z==0:
    if x>y:print('+')
    elif y > x:print('-')
    else:print(0)
else:
    if x >y+z:print('+')
    elif y > x+z:print('z')
    else:print('?')