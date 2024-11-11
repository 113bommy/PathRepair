n = int(input())
a = list(map(int, input().split()))
print("YES" if [i == j for i, j in zip(a, sorted(a))].count(False) == 2 else "NO")