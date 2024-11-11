if __name__ == '__main__':
    n = int(input())
    line = list(map(int, input().split()))
    x, y = map(int, input().split())
    flag = -1
    for i in range(n):
        if x <= sum(line[:i]) <= y and x <= sum(line[i:]) <= y:
            flag = i
            break
        if sum(line[:1]) > y:
            break
    print(flag + 1)
