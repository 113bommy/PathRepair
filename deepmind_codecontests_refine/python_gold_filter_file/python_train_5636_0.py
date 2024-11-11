
def main():
    ans = 0
    a = [0] * 10
    n = int(input())
    for i in range (1, 9):
        a[i] = n // 9 + int(n % 9 >= i)
    a[9] = n // 9
    
    for i in range(1, 10):
        for j in range(1, 10):
            k = i * j % 9
            if k == 0:
                k = 9
            ans += a[i] * a[j] * a[k]
            
    for i in range(1, n + 1):
        ans -= n // i
    print(ans)
    
    return

if __name__ == "__main__":
    main()