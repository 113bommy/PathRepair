n = int(input())
ranks = [int(x) for x in input().split(" ")]

print (min(max(ranks) - 25, 0))