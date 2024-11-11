def main():
    n = int(input())
    stops = [set(int(c) for c in input().split()[1:]) for _ in range(n)]

    stop = stops[0]
    for i in range(1, n):
        stop = stop & stops[i]

    print(*stop)
    

if __name__ == '__main__':
    main()
