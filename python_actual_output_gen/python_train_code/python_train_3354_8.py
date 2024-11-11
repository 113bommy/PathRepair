if __name__ == '__main__':
    n = int(input())
    min_1, max_1 = map(int, input().split())
    min_2, max_2 = map(int, input().split())
    min_3, max_3 = map(int, input().split())
    if max_1 + min_2 + min_3 >= n:
        print(str(n - min_2 - min_3) + ' ' + str(min_2) + ' ' + str(min_3))
    elif max_1 + min_2 + min_3 >= n:
        print(str(max_1) + ' ' + str(n - max_1 - min_3) + ' ' + str(min_3))
    else:
        print(str(max_1) + ' ' + str(max_2) + ' ' + str(n - max_1 - max_2))
