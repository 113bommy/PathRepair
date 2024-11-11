def gcd(a, b):
    if a < b: return gcd(b, a)
    if b==0: return a
    return gcd(b, a%b)

def main():
    input()
    arr = list(map(int, input().split(" ")))
    # print(arr)
    M = max(arr)
    GCD = M
    for x in arr:
        if M-x > 0:
            GCD = gcd(GCD, M-x)
    res = sum([(M-x)//GCD for x in arr])
    print(res, GCD)

if __name__ == "__main__":
    main()
