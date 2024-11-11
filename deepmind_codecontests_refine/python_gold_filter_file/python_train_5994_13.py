def test(s):
    t = [s]
    for i in range(len(s)-1):
        s = s[len(s)-1] + s[:len(s)-1]
        if str(s) not in t:
            t.append(s)
    print(len(t))


if __name__ == '__main__':
    s = input()
    test(s)