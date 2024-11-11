def two(a, b, x, y):
    len = abs(a - x) if abs(a - x) >= abs(x) else x-1
    opt1 = len * b
    len = abs(b - y) if abs(b - y) >= abs(y) else y-1
    opt2 = len * a
    return opt1 if opt1 > opt2 else opt2
    
t = int(input())
i = 0
while (i < t):
    x = input().split()
    print(two(int(x[0]), int(x[1]), int(x[2]) + 1, int(x[3]) + 1))
    i=i+1