import queue

def readTuple():
    return input().split()
def readInts():
    return tuple(map(int, readTuple()))

def solve():
    n, = readInts()
    time = 0
    for _ in range(n):
        u, v = readInts()
        if u > time:
            time = u
            continue
        time -= u
        time = (time//v+1)*v+u
    print(time)

if __name__ == '__main__':
    solve()

