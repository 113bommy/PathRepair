from statistics import pstdev
while True:
    data_count = int(input())
    if data_count == 0:
        break
    print(pstdev(int(x) for x in input().split()))
