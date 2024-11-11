a = list(map(int, input().split()))
print('YNEOS'[len(a) > len(set(a))::2])
