if __name__ == '__main__':
    n = int(input())
    line = list(map(int, input().split()))
    k = int(input())
    for i in range(k):
        x, y = map(int, input().split())
        if x > 1:
            line[i - 2] += y - 1
        if x < n:
            line[i] += line[i - 1] - y
        line[i - 1] = 0
    for i in range(n):
        print(line[i])
