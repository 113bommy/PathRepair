N = int(input())
print("Yes" if sum(map(int, str(N))) % N == 0 else "No")