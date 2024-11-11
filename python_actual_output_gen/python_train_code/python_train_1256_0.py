month = [31, 30, 29, 30, 31, 30, 31, 31, 30, 31, 30, 31]
day = ['Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday', 'Monday', 'Tuesday']
while True:
    m, d = map(int, input().split())
    if m == 0:
        break
    print(day[(sum(month[:m - 1]) + d) % 7])