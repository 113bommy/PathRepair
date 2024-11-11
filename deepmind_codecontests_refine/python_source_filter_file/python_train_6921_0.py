def main():
    n = int(input())
    s = input()
    a = list(map(int, s.split()))
    a.sort()
    ans, sum = 0, 0
    for c in a:
        if (sum <= c):
            ans += 1
        sum += c
    print(ans)

main()