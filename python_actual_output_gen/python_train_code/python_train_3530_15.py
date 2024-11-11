n = int(input())
steward = list(map(int, input().split()))

mini = min(steward)
maxi = max(steward)
result = n-steward.count(mini)-steward.count(maxi)
print(result)

