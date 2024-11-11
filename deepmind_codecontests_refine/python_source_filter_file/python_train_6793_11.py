
def main():
    n, p = [int(i) for i in input().split()]
    a = [int(elem) for i, elem in enumerate(input().split())]
    a = sorted(a)
    ans = []
    mx = a[n - 1]
    base = a[0]
    for i in range(base, mx):
        flag = True
        for j in range(n):
            if i + j < a[j]:
                flag = False
                break
            if (j + p < n and i + j - a[j + p - 1] >= 0) or (i >= a[j] and j >= p - 1):
                flag = False
                break
        if flag:
            ans.append(i)
    print(len(ans))
    print(' '.join(str(i) for i in ans))
main()