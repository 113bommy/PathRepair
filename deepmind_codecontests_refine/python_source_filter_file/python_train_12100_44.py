n = int(input())
Result = []

for i in range (0,n):

    List = list(map(int, input().strip().split()))[:4]

    x = List[0]
    y = List[1]
    diff = y - x
    a = List[2]
    b = List[3]
    if diff % (a+b) is 0:
        Result.append(int(diff/(a+b)))
    else:
        Result.append(-1)

for i in Result:
    print(i)