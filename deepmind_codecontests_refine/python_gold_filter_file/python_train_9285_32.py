n = int(input())
lens = [int(x) for x in input().split(' ')]

lens = sorted(lens)
mid = int(n/2)

print(sum(lens[:mid])**2 + sum(lens[mid:])**2)
