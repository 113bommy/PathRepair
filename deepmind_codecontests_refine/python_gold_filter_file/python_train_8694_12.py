def main():
    a, b, c = map(float, input().split())
    b *= .5
    d = (b * b - a * c) ** .5
    res = ((d - b) / a, -(d + b) / a)
    print(max(res))
    print(min(res))

if __name__ == '__main__':
    main()
