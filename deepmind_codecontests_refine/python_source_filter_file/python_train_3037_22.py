
if __name__ == '__main__':
    n = int(input())
    ss = map(int, input().split())
    q = int(input())
    acc = 0
    sacc = []
    for s in ss:
        acc += s
        sacc.append(acc)

    for _ in range(q):
        l, r = map(int, input().split())
        print((sacc[r - 1] - sacc[l - 1])//10)