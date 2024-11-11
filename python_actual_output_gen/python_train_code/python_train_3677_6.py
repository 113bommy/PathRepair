N = input()
print('Yes' if int(N) % sum(map(int, N)) else 'No')