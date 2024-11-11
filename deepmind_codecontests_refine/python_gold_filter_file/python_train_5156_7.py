def main():
    s = list(input())
    t = s[1]
    s[1] = chr(ord(s[2]))
    s[2] = chr(ord(s[4]))
    s[4] = t
    a = int(0)
    for i in range(5):
        a = a * 10 + int(s[i])
    ans = int(1)
    for i in range(5):
        ans = (ans * a) % 100000
    print('%05d' %ans)


if __name__ == '__main__':
    main()

