x, y, x1, y1 = map(int, input().split())
a, b = map(int, input().split())

def possible():
    diff_x = abs(x - x1)
    diff_y = abs(y - y1)
    if diff_x % a != 0 or diff_y % b != 0:
        return False
    if diff_x / a + diff_y / b <= 2:
        return True
    return False

if possible():
    print("YES")
else:
    print("NO")
