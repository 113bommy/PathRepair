numCases = int(input())
for i in range(numCases):
    hours, minutes = map(int, input().split(" "))
    minRemain = (24 - (hours)+1) * 60 + (60 - minutes)
    print(minRemain)