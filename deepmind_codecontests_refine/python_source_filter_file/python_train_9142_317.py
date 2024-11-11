n = int(input())
print(len(set(list(map(int, [input() for i in range(n+1)])))))