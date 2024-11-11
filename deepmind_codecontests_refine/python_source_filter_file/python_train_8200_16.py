x = list(map(int,input().split()))
print("YES" if len(x)==len(set(x)) else "NO")