__copyright__ = ''
__author__ = 'Son-Huy TRAN'
__email__ = "sonhuytran@gmail.com"
__doc__ = ''
__version__ = '1.0'


def main() -> int:
    n = int(input())

    if n <= 1:
        print(-1)
    else:
        result = [str(i) for i in range(n, 0, -1)]
        print(' '.join(result))

    return 0


if __name__ == '__main__':
    exit(main())