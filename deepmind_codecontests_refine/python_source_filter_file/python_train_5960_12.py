from sys import stdin

def main():
    n, m, k = map(int, stdin.readline().split())
    for _ in range (k):
        x, y = map(int, stdin.readline().split())
    ans = str()
    for _ in range (n - 1):
        ans += 'U'
    for _ in range (m - 1):
        ans += 'L'

    for i in range (n - 1):
        if i % 2:
            char = 'L'
        else:
            char = 'R'
        for _ in range (m - 1):
            ans += char
        ans += 'D'

    print (len(ans))
    print (ans)
main()