n = int(input())
ranks = [int(x) for x in input().split(" ")]

print (max(max(ranks) - 25, 0))