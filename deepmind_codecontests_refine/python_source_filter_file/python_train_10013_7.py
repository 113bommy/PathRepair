def main():
    b,g,n = int(input()),int(input()),int(input())

    ans = 0
    for i in range(n):
        pg = i
        pb = n - i
        if pg <= g and pb <= b:
            ans += 1

    print(ans)

main()
