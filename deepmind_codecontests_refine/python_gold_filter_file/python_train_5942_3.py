import statistics

while True:
    n = int(input())
    if n == 0:
        break

    s = map(float, input().split())
    print(statistics.pstdev(s))