# =============================
#   Problem - 27A - Next Test
#       Python3
#   Author - wdaubry
# =============================

def main():
    from sys import stdout

    n = int(input())
    lis = list(map(int, input().split()))

    res = n
    for i in range(n):
        if lis.count(i) == 0:
            res = i
            break;

    stdout.write(str(res))

if __name__ == '__main__':
    main()
