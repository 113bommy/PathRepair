N = int(input())
p = [int(s) for s in input().split()]

print('Yes' if sum(map(lambda x: x[0] == x[1], zip(p, sorted(p)))) >= N - 2 else 'No')
