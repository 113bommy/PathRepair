def main():
    n = int(input())
    s = input()
    a = []
    b = []
    curr = []
    for i in range(n):
        a1, b1 = list(map(int, input().split()))
        a.append(a1)
        b.append(b1)

    for i in range(n):
        if s[i] == "0":
            curr.append(False)
        else:
            curr.append(True)

    m = 0

    for i in range(5000):
        cm = 0
        for k in curr:
            if k:
                cm += 1
        for d in range(n):
            if i - b[d] > 0 and (i - b[d]) % a[d] == 0:
                curr[d] = not curr[d]
        m = max(m, cm)

    print(m)

if __name__ == "__main__":
    main()
