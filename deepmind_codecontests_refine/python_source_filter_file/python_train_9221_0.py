from collections import deque

MAX_A = 1000
     
     
def main():
    n, k = map(int, input().split())
    a = set(int(x) - n for x in input().split())
     
    visited = [False] * (2 * n + 1)
    visited[n] = True
    Q = deque()
    Q.append((n, 0))
     
    result = None
    while Q:
        u, l = Q.popleft()
        l += 1
        for ai in a:
            v = u + ai
            if v == n:
                result = l
                break
            if 0 <= v < len(visited) and not visited[v]:
                visited[v] = True
                Q.append((v, l))
     
        if result is not None:
            break
     
    if result is None:
        result = -1
     
    print(result)
     
     
if __name__ == '__main__':
    # import sys
    # sys.stdin = open("E.txt")
    main()