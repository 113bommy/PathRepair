I = lambda: list(map(int, input().split()))
n = int(input())
b = I()
print(b[0] + sum([abs(b[i]-b[i-1]) for i in range(1,n)]))