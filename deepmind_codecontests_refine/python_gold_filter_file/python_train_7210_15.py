def main():
    n = int(input())
    b = [int(i) for i in input().split(' ')]

    ans = 0
    while n > 0:
        ans = ans % 7 + 1
        n -= b[ans-1]
        
    print(ans)

if __name__ == "__main__":
    main()