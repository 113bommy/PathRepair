import sys

input = sys.stdin.readline


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def lcm(a, b):
    return (a * b) / gcd(a, b)

def main():
    for _ in range(int(input())):
        n=int(input())
        # a=list(map(int, input().split()))
        s=input()
        c=0
        for i in range(1,len(s)):
            if s[i]==s[i-1]:
                c+=1
        print(c//2)

    return

if __name__=="__main__":
    main()

