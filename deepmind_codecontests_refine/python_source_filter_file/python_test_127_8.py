def main():
    from collections import Counter

    for _ in range(int(input())):
        s = list(input())[:-1]
        #print(s)
        t = input()
        f = (t == "abc" and "a" in s)
        #print(f)
        C = Counter(s)
        ans = ""
        i = 0
        while i < 26:
            if i == 1:
                if f:
                    ans += "c" * C[chr(2 + ord("a"))]
                    ans += "b" * C[chr(1 + ord("a"))]
                else:
                    ans += "b" * C[chr(1 + ord("a"))]
                    ans += "c" * C[chr(2 + ord("a"))]
                i += 2
                continue
            else:
                ans += chr(i + ord("a")) * C[chr(i + ord("a"))]
            i += 1
        print(ans)
if __name__ == '__main__':
    main()
    