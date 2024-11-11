import math


x, y = [int(x) for x in input().split()]
biggerValue = int((x + y) / 2 + abs(x - y) / 2)
smallerValue = int((x + y) / 2 - abs(x - y) / 2)
takeBoth = smallerValue
takeSame = math.floor((biggerValue - smallerValue) / 2)
print(takeBoth, takeSame)
