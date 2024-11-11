def main():
    from collections import Counter
    k = int(input())
    s = Counter(input())
    for c,v in s.items():
        if v%k != 0:
            print(-1)
            return
    base = ''
    for c,v in s.items():
        base += c * (k//v)
    print(base * k)

main()
