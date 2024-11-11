N = int(input())
*l, = map(int, input().split())
print("YES" if len(l)==len(set(l)) else "NO")