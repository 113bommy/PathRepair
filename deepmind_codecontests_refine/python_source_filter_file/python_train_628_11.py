a, b, c = map(int, input().split())
l = [n for n in range (a,b) if c % n == 0]
print(len(l))