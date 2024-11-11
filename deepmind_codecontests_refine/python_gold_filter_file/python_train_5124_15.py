import sys

t = int(sys.stdin.readline())

for i in range(t):
    count = 0
    n = int(sys.stdin.readline())
    s = sys.stdin.readline()

    # replace AP with AA until s has no more 'AP'
    while s != s.replace('AP', 'AA'):
        s = s.replace('AP', 'AA')
        count += 1
    print(count)
