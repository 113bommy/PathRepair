import math

n, m, k = [int(s) for s in input().split()]

hors = [[int(s) for s in input().split()] for _ in range(n)]
vers = [[int(s) for s in input().split()] for _ in range(n-1)]
    
def get_nbs(i, j):
    res = []
    if i > 0:
        res.append((i-1, j, vers[i-1][j]))
    if i < n - 1:
        res.append((i+1, j, vers[i][j]))
    if j > 0:
        res.append((i, j-1, hors[i][j-1]))
    if j < m - 1:
        res.append((i, j+1, hors[i][j]))
    return res

def print_res(arr = None):
    for i in range(n):
        print(' '.join([str(arr[i][j]*2) if arr else '-1' for j in range(m)]))

if k%2 == 1:
    print_res()
else:
    arr1 = [[0 for _ in range(m)] for _ in range(n)]
    arr2 = [[0 for _ in range(m)] for _ in range(n)]
#    arr = [[[0]*(k//2+1) for _ in range(m)] for _ in range(n)]
    prev = arr1
    cur = arr2    
    for kk in range(1, k//2+1):
        for i in range(n):
            for j in range(m):
                min_skuk = math.inf
                if i > 0:
                    min_skuk = min(min_skuk, prev[i-1][j]+vers[i-1][j])
                if i < n - 1:
                    min_skuk = min(min_skuk, prev[i+1][j]+vers[i][j])
                if j > 0:
                    min_skuk = min(min_skuk, prev[i][j-1]+hors[i][j-1])
                if j < m - 1:
                    min_skuk = min(min_skuk, prev[i][j+1]+hors[i][j])
                cur[i][j] = min_skuk
        prev, cur = cur, prev
    print_res(cur)