def main():
    n,x = map(int, input().split())
    
    watched = 0
    current = 1
    
    for _ in range(n):
        l,r = map(int, input().split())
        watched += r - (l - (l - current) % x) + 1
        current = r + 1
    print(watched)

if __name__ == '__main__':
    main()   