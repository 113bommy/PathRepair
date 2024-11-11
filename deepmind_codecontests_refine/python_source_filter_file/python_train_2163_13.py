n = int(input())
a = list(map(int, input().split()))
m = 1000000007
print(int(((sum(a)**2 - sum(map(lambda x: x**2, a))) / 2) % m))