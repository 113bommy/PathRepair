input()
s = input()
k = [s.count(x) for x in 'ACGT']
print(pow(k.count(min(k)), len(s), 10 ** 9 + 7))