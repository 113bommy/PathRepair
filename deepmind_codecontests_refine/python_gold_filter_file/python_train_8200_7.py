m = int(input())
n = list(map(int,input().split()))
print("YES" if len(set(n)) == m else "NO")