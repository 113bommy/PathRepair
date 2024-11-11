# https://codeforces.com/contest/1288/problem/A

def main():
    n, d = map(int, input().split())
    if n >= d:
        print('YES')
    else:
        for i in range(1, n):
            dx = i + (d+i)//(i+1)
            if n >= dx:
                print('YES')
                break
        else:
            print('NO')

t = int(input())
for i in range(t):
    main()
