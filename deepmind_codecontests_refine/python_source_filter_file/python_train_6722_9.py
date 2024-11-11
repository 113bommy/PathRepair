def main():
    n = int(input())
    mx = n
    for i in range(1, n//2):
        if n%i == 0 and n//i - i > 0:
            if mx > n//i - i:
                mx = n//i - i
                a = i
                b = n//i
    print(a,b)
    
main()