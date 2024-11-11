def main():
    import sys
    input = sys.stdin.readline
    
    def solve():
        n, m, k = map(int, input().split())
        arr = list(map(int, input().split()))
        
        curr = m
        for i in range(n - 1):
            diff = arr[i] - (arr[i + 1] - k)
            curr += diff
            if curr < 0:
                print("NO")
                return
        
        print("YES")
        return
    
    for _ in range(int(input())):
        solve()
    
    return 0

main()