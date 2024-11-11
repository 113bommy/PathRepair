_, *a = map(int, open(0).read().split())
odd = sum(not ai % 2 for ai in a) + 1
print('YNEOS'[odd % 2::2])