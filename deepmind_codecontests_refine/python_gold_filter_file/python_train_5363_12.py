

n,p,q = map(int, input().split())
def main():
    s = input()
    f = 0
    for i in range(n // p + 1):
        if (n - p * i) % q == 0:
            f = 1
            break
    if n % p == 0:
        i = n // p
        f = 1
    if not f: print(-1)
    else:
        print(i + (n - i * p) // q)
        for j in range(i):
            print(s[j * p: j * p + p])
        for j in range((n - i * p) // q):
            print(s[i * p + q * j: i * p + q * j + q])
            
            
main()
        
            