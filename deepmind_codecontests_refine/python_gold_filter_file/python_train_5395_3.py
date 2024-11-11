N = int(input())

def factors(n):
    return sum(0 == n % (1 + x) for x in range(N))
print(sum(map(lambda x: factors(x) == 8, range(105, N+1, 2))))