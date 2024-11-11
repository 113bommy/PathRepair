from fractions import gcd
import sys
input = sys.stdin.readline

N,M=map(int,input().split())
List=list(map(lambda x:int(x)/2,map(int, set(input().split()))))

def main():
    LCM=1

    for i in List:
        LCM*=i/gcd(LCM,i)

    for i in List:
        if LCM/i%2==0:
            print(0)
            exit()

    print(int(M//(LCM*2)+M%(LCM*2)//LCM))


if __name__ == '__main__':
    main()