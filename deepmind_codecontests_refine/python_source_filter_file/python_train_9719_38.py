import math

def input_ints():
    return list(map(int, input().split()))

def solve():
    a, b, c = input_ints()
    x = math.sqrt(b * c / a)
    y = math.sqrt(c * a / b)
    z = math.sqrt(a * b / c)
    print(4 * (x + y + z))

if __name__ == '__main__':
    solve()
