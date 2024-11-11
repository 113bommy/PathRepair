def main():
    from sys import stdin, stdout
    (n, m) = map(int, stdin.readline().strip().split(' '))
    a = [0] + list(map(int, stdin.readline().strip().split(' ')))
    r = [0] * (n + 1) # r[i] stores highest index to right of i st. i..ri is nondecreasing
    l = [0] * (n + 1) # l[i] stores smallest index to the left of i st. li..i is nonincreasing

    l[1] = 1
    r[n] = n

    for i in range(2, n):
        if a[i - 1] >= a[i]:
            l[i] = l[i - 1]
        else:
            l[i] = i

    for i in range(n - 1, 0, -1):
        if a[i + 1] >= a[i]:
            r[i] = r[i + 1]
        else:
            r[i] = i

    for i in range(m):
        (a, b) = map(int, stdin.readline().strip().split(' '))
        if r[a] >= l[b]:
            stdout.write("Yes\n")
        else:
            stdout.write("No\n")
main()
