
        
def main():
    import sys

    def input(): return sys.stdin.readline().rstrip()

    n = int(input())
    a = [int(input()) for _ in range(n)]
    a.sort(reverse=True)
    if n%2 == 0:
        ans = 2*(sum(a[:n//2])-sum(a[n//2:]))
        ans += a[n//2]-a[n//2-1]
    else:
        ans = 2*(sum(a[:n//2])-sum(a[n//2+1:]))
        tmp = min(a[n//2]-a[n//2-1], a[n//2+1]-a[n//2])
        ans += tmp
    print(ans)



                
if __name__ == '__main__':
    main()