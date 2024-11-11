import sys
#input = sys.stdin.readline

def main():
    N = int(input())
    s = [list(map(str,input())) for _ in range(N)]
    s += s
    ans = 0
    for i in range(N):
        b = True
        for x in range(N):
            for y in range(N):
                if s[x+i][y] != s[y+i][x]:
                    b = False
        if b:
            ans += N
    
    print(ans)

if __name__ == "__main__":
    main()
