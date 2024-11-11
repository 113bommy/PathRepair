def main():
    x, y = (int(_) for _ in input().split())
    if x <= y:
        print(min(y-x, x+y+1))
    else:
        print(min(x-y+2, abs(x+y)+1))
    return

if __name__ == '__main__':
    main()
