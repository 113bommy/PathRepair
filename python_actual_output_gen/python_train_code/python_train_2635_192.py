a, b = map(int, input().split())

c = b - a
N = (1+c)*c/2
print(b-N)