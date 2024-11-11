def solve():
    n = int(input())
    S = [int(x)-1 for x in input().split()]
    k = len([x for i,x in enumerate(S) if i == x])
    
    return k + (len(S)-k)//2

print(solve())
