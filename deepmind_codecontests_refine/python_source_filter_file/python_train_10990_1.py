if __name__ == '__main__':
    refer = (0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
    m, d = map(int, input().split())
    print((refer[m] + d - 8) // 7 + 1)
