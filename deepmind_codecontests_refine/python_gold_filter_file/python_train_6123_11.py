modulo = 1000000007

import sys
sys.setrecursionlimit(100000009)


muchii = []


def recursie(x, y):
    alb = 1
    negru = 1
    for elem in muchii[x]:
        if elem == y:
            continue
        result_1, result_2 = recursie(elem, x)
        alb = (alb * (result_1 + result_2)) % modulo
        negru = (negru * result_1) % modulo
    return alb, negru
    

if __name__ == "__main__":
    input = sys.stdin.readline
    n = int(input())
    for i in range(n):
        muchii.append([])
        
    for i in range(n-1):
        numbers = list(map(int, input().split(" ")))
        
        x = numbers[0]
        y = numbers[1]
        
        muchii[x-1].append(y-1)
        muchii[y-1].append(x-1)
        
    result_1, result_2 = recursie(0, None)
    
    result = (result_1 + result_2) % modulo
    
    print(result)
