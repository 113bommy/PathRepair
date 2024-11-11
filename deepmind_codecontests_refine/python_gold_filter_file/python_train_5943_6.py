import statistics
while True:
    n = input()
    if n == '0': break
    print(statistics.pstdev(map(int, input().split())))