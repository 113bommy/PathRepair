if __name__ == "__main__":
    n = int(input())
    prev = [1 for _ in range(n)]
    a = 0
    for _ in range(n - 1):
        pres = [1]
        for i in range(1, n):
            pres.append(pres[i-1] + prev[i])
            if i == n-1:
                a = pres[n-1]
        prev = pres.copy()
    print(a)