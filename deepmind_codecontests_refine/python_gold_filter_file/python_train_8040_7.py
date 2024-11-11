
def solve():
    n = int(input())
    arr = list(map(int,input().split(' ')))
    res = []

    for i in range(n):
        res.append((i + arr[i]) % n)
    
    if len(set(res)) != len(res):
        print('NO')
    else:
        print('YES')

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()