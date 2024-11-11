n = int(input())
print("I become the guy." if n==len(set(map(int, input().split())).union(map(int, input().split()))) else "Oh, my keyboard!")
