import logging, sys
logging.basicConfig(level=logging.INFO)

def main():
    test = int(sys.stdin.readline())
    while(test > 0):
        test -= 1
        n = int(sys.stdin.readline())
        if(n % 2 == 0):
            print('YES')
        else:
            print('NO')

if __name__ == "__main__":
    try:
        sys.stdin = open('input.txt', 'r')
        sys.stdout = open('output.txt', 'w')
    except:
        pass
    main()