N = int(input())
L = list(map(int, input().split()))
print("YES" if max(L)*2<sum(L) else "NO")