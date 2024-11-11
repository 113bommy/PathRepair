N,K = map(int, input().split())
pi= list(map(int, input().split()))

print(sum(sorted(pi)[:N]))