def suf(s):
    s = s.lower()
    if s.count('po'):
        return 'FILIPONO'
    elif s.count('desu') or s.count('masu'):
        return 'JAPANESE'
    elif s.count('mnida'):
        return 'KOREAN'


if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        s = input().strip()
        print(suf(s))
