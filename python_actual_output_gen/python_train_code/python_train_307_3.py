if __name__ == '__main__':
    n,a,b,c = [int(input()) for _ in range(4)]
    if a < (b-c):
        print(n//a)
    else:
        k = 1+(n-b)//(b-c)
        print(k + (n - k*b + k*c)//a)
