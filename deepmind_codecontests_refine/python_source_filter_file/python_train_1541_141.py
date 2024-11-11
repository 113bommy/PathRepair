a = list(map(int, input().split()))
print('bust' if sum(a) >= 22 else 'Win')