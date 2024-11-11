def main():
    n,m,t = [int(elem) for elem in input().split()]
    ans = 0
    f = lambda x : 1 if x == 0 else x*f(x-1)
    c = lambda k,m : f(m)//f(k)//f(m-k)
    for i in range(4,n+1):
        for j in range(1,m+1):
            if i + j == t:
                ans += c(i,n)*c(j,m)
    print(ans)
if __name__ == '__main__':
    main()
