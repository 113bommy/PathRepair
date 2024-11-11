from collections import defaultdict as dd
def main():
    N, M = map(int, input().split())

    D = dd(list)

    for m in range(M):
        a, b = map(int, input().split())
        D[a-1].append(b-1)

    for d in D[0]:
        if N-1 in D[d]:
            print('POSSIBLE')
            return

    print('IMPOSSIBLE')
        

if __name__ == "__main__":
    # global stime
    # stime = time.clock()
    main()