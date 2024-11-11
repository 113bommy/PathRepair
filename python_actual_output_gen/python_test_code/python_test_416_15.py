if __name__ == '__main__':
    n = int(input())
    last, count, current_max = -1, 0, 0
    for a in map(int, input().split()):
        if a > last:
            count += 1
            current_max = max(current_max, count)
        else:
            count = 1
        last = a
    print(count)
