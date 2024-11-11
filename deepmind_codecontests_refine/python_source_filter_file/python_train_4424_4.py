def main():
    s = input()

    for i in range(len(s)):
        for j in range(i + 1, len(s)):
            if s[:i] + s[j:] == "CODEFORCES":
                print("YES")
                return
    else:
        print("NO")

main()
