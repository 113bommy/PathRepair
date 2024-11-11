def main():
    n, k = map(int, input().split(' '))
    result = [n//i*max(0,i-k) + max(0, n%i-k+1) for i in range(1, n+1)]
    if k == 0:
        print(sum(result)-n)
    else:
        print(result)
main()