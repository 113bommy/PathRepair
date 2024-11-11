def main():
    import sys
    input = sys.stdin.readline
    
    MOD = 998244353
    n, m = map(int, input().split())
    
    n, m = min(n, m), max(n, m) - min(n, m)
    print(pow(4, n, MOD) * pow(2, m, MOD))
    
    return 0

main()