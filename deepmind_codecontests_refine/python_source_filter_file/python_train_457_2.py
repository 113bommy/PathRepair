def main():
    from sys import stdin, stdout
    n, l = [int(i) for i in stdin.readline().split()]
    a = [int(i) for i in stdin.readline().split()]
    best = 0
    for i in range(l, max(a)):
        count = 0
        for j in a: count += j // i
        best = max([best, count * i])
    stdout.write(str(best))

if __name__ == "__main__":
    main()