import sys
input = sys.stdin.readline


def print(s): return sys.stdout.write(s + '\n')


n, k = map(int, input().split())
a = [1 if x == 'R' else 0 for x in input().strip()]

steps = []
# fastest
while True:
    steps.append([i for i in range(n - 1) if a[i] == 1 and a[i + 1] == 0])
    for i in steps[-1]:
        a[i], a[i + 1] = 0, 1

    if not steps[-1]:
        del steps[-1]
        break


if not len(steps) <= k <= sum(len(s) for s in steps):
    print('-1')
    sys.exit(0)

need_more = k - len(steps)
for step in steps:
    if need_more == 0:
        print(str(len(step)) + ' ' + ' '.join(map(lambda x: str(x + 1), step)))
    elif need_more >= len(step) - 1:
        for x in step[::-1]:
            print('1 ' + str(x + 1))
        need_more -= len(step) - 1
    else:
        for x in step[::-1][:need_more]:
            print('1 ' + str(x + 1))
        print(str(len(step[::-1][need_more:])) + ' ' + ' '.join(map(lambda x: str(x + 1), step[::-1][need_more:])))
        need_more = 0
