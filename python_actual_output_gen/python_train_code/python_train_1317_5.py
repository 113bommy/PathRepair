if __name__ == '__main__':
    cin = input
    d = "31 28 31 30 31 30 31 31 30 31 30 31 "
    y = "31 29 31 30 31 30 31 31 30 31 30 31 "
    s = d * 3 + y + d
    n = int(input())
    a = " ".join(input().split())
    print("YNEOS"[not a in s::2])