import math
def main():
    a ,b, c, d = map(int,input().split())
    if (math.ceil(a / c) * b) < b + d:
        print('YES')
    else:
        print('NO')
main()