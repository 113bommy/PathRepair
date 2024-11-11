days = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']
nums = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
while True:
    try:
        m, d = map(int, input().split())
        if not m:
            break
    except:
        break
    print(days[(sum(nums[:m - 1]) + d) % 7 + 2])