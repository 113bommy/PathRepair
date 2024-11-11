def main():
    n, a, b = list(map(int, input().split()))
    x_list = list(map(int, input().split()))
    res = list()

    for x in x_list:
        res.append(str(x * a % b))

    print(' '.join(res))

if __name__ == '__main__':
    main()