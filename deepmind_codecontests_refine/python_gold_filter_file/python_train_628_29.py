a,b,c = map(int, input().split())
print(len([1 for i in range(a, b+1) if c % i == 0]))
