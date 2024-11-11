for _ in range(int(input())):
    s = input()
    if s == "b" * len(s) or s == "a" * len(s):
        print(s)
        continue
    print(s[:len(s) - 1] + "a")