t = int(input())

def solve():
    b = int(input())
    print(b)
    print(' '.join([str(i) for i in range(1,b+1)]))

for i in range(t):
    solve()