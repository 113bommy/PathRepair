letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
           'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
N = int(input())
for _ in range(N):
    n, a, b = map(int, input().split())
    ans = ""
    for i in range(n):
        ans += letters[i % 26]
    print(ans)