A,B,X = map(int,input().split())
print("YES" if X-A <= B-A and A <= X else "NO")