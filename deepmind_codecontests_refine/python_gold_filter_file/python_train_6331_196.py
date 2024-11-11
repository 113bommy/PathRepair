_, *D = map(int, open(0).read().split())
print(sum(D) - max(D)//2)