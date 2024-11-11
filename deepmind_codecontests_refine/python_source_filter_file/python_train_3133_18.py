def main():
    #string         input()
    #integer        int(input())
    #integers       map(int, input().split())
    #array of ints  list(map(int, input().split()))
    s, t = input(), input()
    a = len(s)
    b = len(t)
    i = min(a, b)
    j = max(a, b)
    ret = a + b
    if a <= b:
        while i >= 0 and s[i - 1] == t[j - 1]:
            i -= 1
            j -= 1
            ret -= 2
    else:
        while i >= 0 and t[i - 1] == s[j - 1]:
            i -= 1
            j -= 1
            ret -= 2
    print(ret)
    return 0
main()