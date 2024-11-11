def main():
    n, m = map(int, input().split())
    lights = []
    for _ in range(n):
        lights += list(map(int, input().split()))[1:]
    count_light = set(lights)
    if 0 in count_light and len(count_light)-1 == m:
        print("YES")
    elif 0 not in count_light and len(count_light) == m:
        print("YES")
    else:
        print("NO")


if __name__ == '__main__':
    main()
