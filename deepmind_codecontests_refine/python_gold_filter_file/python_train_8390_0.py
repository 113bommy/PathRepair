from sys import stdin, stdout
from math import factorial
from math import log10


def check(pw, values, k):
    n = len(values)
    
    matr = [[0 for i in range(n)] for j in range(n)]
    res = [[0 for i in range(n)] for j in range(n)]
    pp = [[0 for i in range(n)] for j in range(n)]
    
    for i in range(n):
        for j in range(n):
            matr[i][j] = int(i >= j)
    
    for i in range(n):
        res[i][i] = 1
        
    while pw:
        if pw & 1:
            for i in range(n):
                for j in range(n):
                    pp[i][j] = 0
            
            for i in range(n):
                for j in range(n):
                    for z in range(n):
                        pp[i][j] += res[i][z] * matr[z][j]
            
            for i in range(n):
                for j in range(n):
                    res[i][j] = pp[i][j]
        
        for i in range(n):
            for j in range(n):
                pp[i][j] = 0        

        for i in range(n):
            for j in range(n):
                for z in range(n):
                    pp[i][j] += matr[i][z] * matr[z][j]        

        
        for i in range(n):
            for j in range(n):
                matr[i][j] = pp[i][j]

        pw >>= 1
    
    ans = 0
    for i in range(n):
        ans += values[i] * res[i][0]
            
    
    return ans >= k


def stupid(values, n, k):
    ans = values[:]
    
    if max(ans) >= k:
        return 0
    
    cnt = 0
    while ans[-1] < k:
        for i in range(1, n):
            ans[i] += ans[i - 1]
        
        cnt += 1
        q = ans[-1]
    
    return cnt


def clever(values, n, k):
    if max(values) >= k:
        return 0
    
    l, r = 0, 10 ** 18 + 100
    
    while r - l > 1:
        m = (l + r) >> 1
        
        if check(m, values, k):
            r = m
        else:
            l = m
            
    return r


def main():
    n, k = map(int, stdin.readline().split())
    values = list(map(int, stdin.readline().split()))[::-1]
    
    while not values[-1]: #Проблема в том что ты удаляешь
        values.pop()
    
    n = len(values)

    
    if n >= 10:
        stdout.write(str(stupid(values[::-1], n, k)) + '\n')
    else:
        stdout.write(str(clever(values, n, k)) +  '\n')
    
    
main()