def solve():
    n = int(input())
    if n%2==0:
        print('YES')
    else:
        print('NO')

def main():
    t=int(input())
    for _ in range(t):
        solve()

if __name__=='__main__':
    main()