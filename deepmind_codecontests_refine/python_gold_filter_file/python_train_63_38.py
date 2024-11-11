_, m = map(int, input().split())
a = max([int(i) for i in input().split() if m%int(i)==0])
print(m//a)