# =============================
#   Problem - 27A - Next Test
#       Python3
#   Author - wdaubry
# =============================

def main():
    from sys import stdout

    n = int(input())
    lis = list(map(int, input().split()))

    res = n+1
    for i in range(1, n+1):
        if lis.count(i) == 0:
            res = i
            break;

    stdout.write(str(res))

if __name__ == '__main__':
    main()
