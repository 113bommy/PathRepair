X = input()
print('Yes' if X % sum(map(int, X)) == 0 else 'No')