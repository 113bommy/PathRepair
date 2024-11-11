from collections import deque

# https://e-maxx.ru/algo/bfs
def bws(A, si):
    used = [0] * len(A)
    d = [0] * len(A)
    p = [0] * len(A)
    used[si] = True
    p[si] = -1

    q = deque([si])
    while len(q) > 0:
        vert = q.popleft()
        for vi in range(len(A)):
            if vi == vert:
                continue
            if vi == p[vert]:
                continue
            if A[vi] & A[vert] == 0:
                continue
                
            if used[vi] == False:
                used[vi] = True
                q.append(vi)
                d[vi] = d[vert] + 1
                p[vi] = vert
            else:
                # restore paths s -> vi and vert -> s
                cycle = set()
                k = vert
                while k != si:
                    cycle.add(k)
                    k = p[k]
                k = vi
                while k != si:
                    cycle.add(k)
                    k = p[k]
                cycle.add(si)
                return cycle
     
    return set()

def main():
    n = int(input())
    A = list(map(int, input().split()))
    assert n == len(A)


    A = list(filter(lambda x: x > 0, A))
    n = len(A)

    to_check = set(range(n))

    res = -1
    while (len(to_check) > 0):
        si = to_check.pop()
        cycle = bws(A, si)
        r = len(cycle)
        if r != 0:
            res = min(res, r) if res != -1 else r
            if res == 3: # bootleg
                print(res)
                return
            #to_check = to_check - cycle

        
    print(res)


import sys
input = sys.stdin.readline
if __name__ == "__main__":
    main()