# ?????¶??????????±???????????????°??????
import sys

def main():
    n = int(sys.stdin.readline().strip())

    for _ in range(n):
        x = sys.stdin.readline().strip()
        y = sys.stdin.readline().strip()

        if len(x) > 80 or len(y) > 80:
            print('overflow')
        else:
            ans = int(x) + int(y)
            if len(str(ans)) > 80:
                print('overflow')
            else:
                print(x + y)

if __name__ == '__main__':
    main()