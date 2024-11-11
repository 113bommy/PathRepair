n = int(input())
votesE = [int(x) for x in input().split(' ')]
k = max(votesE)
votesA = [k - x for x in votesE]
while sum(votesA) < sum(votesE):
    k += 1
    votesA = [k - x for x in votesE]
print(k)