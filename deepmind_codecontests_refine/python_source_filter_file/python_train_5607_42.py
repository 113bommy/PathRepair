def main():
    x, y = map(int, input().split())
    print(min(max(x+y, y-x+2), abs(x+y)+1)
if __name__ == '__main__':
    main()