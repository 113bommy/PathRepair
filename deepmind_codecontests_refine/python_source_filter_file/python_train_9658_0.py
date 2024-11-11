N = int(input())
a = list(map(int, input().split()))
print(len([i for i, ai in enumerate(a) if i%2 and ai%2]))
