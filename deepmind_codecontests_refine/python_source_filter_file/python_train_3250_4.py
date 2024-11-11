def main():
    for _ in range(int(input())):
        n = int(input())
        if n < 10:
            print(n)
        else:
            k = 1
            l = 1
            ans = 0
            while k < n:
                found = False
                for x in range(1, 10):
                    if x * k > n: 
                        found = True
                        break
                    ans += 1
                if found:
                    break
                k += 10**l
                l += 1
            print(ans)

if __name__ == "__main__":
    main()