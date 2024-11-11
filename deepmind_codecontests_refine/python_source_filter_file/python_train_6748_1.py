import sys
input = sys.stdin.readline
sys.setrecursionlimit(pow(10, 6))


def main():
    n, m = map(int, input().split())
    s = input().strip()
    ab = [tuple(map(int, input().split())) for _ in range(m)]
    edges = [[] for _ in range(n)]
    for a, b in ab:
        edges[a - 1].append(b - 1)
        edges[b - 1].append(a - 1)
    
    ab = [[0, 0] for i in range(n)]
    stack = []
    for i in range(n):
        for e in edges[i]:
            if s[e] == 'A':
                ab[i][0] += 1
            else:
                ab[i][1] += 1
        if ab[i][0] == 0 or ab[i][1] == 0:
            stack.append(i)
    
    deleted = [False for i in range(n)]
    while len(stack) > 0:
        q = stack.pop()
        if deleted[q]:
            continue
        deleted[q] = True
        for e in edges[q]:
            if not deleted[e]:
                if s[q] == 'A':
                    ab[e][0] -= 1
                    if ab[e][0] == 0:
                        stack.append(e)
                else:
                    ab[e][1] -= 1
                    if ab[e][1] == 0:
                        stack.append(e)
    
    for d in deleted:
        if not d:
            print("Yes")
            break
    else:
        print("no")


if __name__ == '__main__':
    main()
