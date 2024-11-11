import statistics
while input() != "0":
    data = list(map(float, input().split()))
    print("{0:.6f}".format(statistics.pstdev(data)))