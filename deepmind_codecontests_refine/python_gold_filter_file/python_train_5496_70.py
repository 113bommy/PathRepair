import sys
def main():
    input = sys.stdin.readline
    M=int(input())
    DC=[tuple(map(int, input().split())) for _ in range(M)]
    Dsum=sum(d*c for d,c in DC)
    Csum=sum(c for d,c in DC)
    print(Csum-1 + (Dsum-1)//9)

if __name__ == '__main__':
    main()