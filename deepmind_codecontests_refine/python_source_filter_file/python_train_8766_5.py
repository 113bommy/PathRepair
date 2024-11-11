def main():
    x0, y0, ax, ay, bx, by = map(int, input().split())
    xs, ys, t = map(int, input().split())
    arr1 = []
    arr2 = []
    while (x0 < 1000000000000000000000 and y0 < 1000000000000000000000):
        arr1.append(x0)
        arr2.append(y0)
        x0 = x0 * ax + bx
        y0 = y0 * ay + by
    mx = 0
    for i in range(len(arr1)):
        for j in range(i + 1, len(arr1)):
            if min(abs(xs - arr1[i]) + abs(ys - arr2[i]), abs(xs - arr1[j]) + abs(ys - arr2[j])) + abs(
                    arr1[i] - arr1[j]) + abs(arr2[i] - arr2[j]) <= t:
                mx = max(mx, j - i + 1)
    print(mx)


main()
