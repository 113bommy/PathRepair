import random

def solve():
    n = int(input())
    res = []
    for i in range(1, n+1):
        res.append(i)
    random.shuffle(res)
    print(res, '\n')

if __name__ == "__main__":
    t = int(input())
    while t:
        solve()
        t-=1
