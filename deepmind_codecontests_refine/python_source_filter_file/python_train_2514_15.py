def main():
    n = int(input())
    a = list(map(int, list(input())))
    c = list(map(int, input().split()))
    i = 0
    while i < n and c[a[i] - 1] <= a[i]:
        i += 1
    if i == n:
        print("".join(map(str, a)))
    else:
        d = a[i]
        l = c[d - 1]
        while i < n and c[a[i] - 1] > a[i]:
            a[i] = c[a[i] - 1]
            i += 1    
        print("".join(map(str, a)))
main()