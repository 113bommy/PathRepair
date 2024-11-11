def main():
    n = int(input())
    for i in range(n):
        Ball = map(int,input().split())
        l = r = 0
        for value in Ball:
            if value > r:
                r = value
            elif value > l:
                l = value
            else:
                print("NO")
                r = -777
                break
            if r < l:
                r,l = l,r
            
        if r == -777:
            continue
        else:
            print("Yes")

if __name__ == '__main__':
    main()

