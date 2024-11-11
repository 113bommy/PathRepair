def main():
    s, k = input(), int(input())
    if not len(s) % k:
        le = len(s) // k
        if all(t == t[::-1] for t in (s[i:i + le] for i in range(0, le, len(s)))):
            print("YES")
            return
    print("NO")


if __name__ == "__main__":
    main()
