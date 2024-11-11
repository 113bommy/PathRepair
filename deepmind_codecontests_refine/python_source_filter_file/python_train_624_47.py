a, b, c = [int(w) for w in input().split()]
print(len([i for i in range(a, b+1) if i % c == 0]))