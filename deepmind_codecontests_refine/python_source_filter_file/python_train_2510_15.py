import math

C = 10**18

def main():
    n = int(input())
    cnt = 0
    for i in range(1, 1 + int(math.sqrt(n))):
        if n % i == 0:
            cnt += 2
        if n // i == i:
            cnt -= 1
    print(cnt)


if __name__ == "__main__":
    main()
