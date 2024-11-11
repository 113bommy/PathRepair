def main():
    n = int(input())
    pars = list()
    for i in range(n):
        l, r = map(int, input().split())
        pars.append((l, r))
    k = int(input())
    
    for i in range(n):
        if pars[i][0] <= k - 1 <= pars[i][1]:
            if k - 1 == pars[i][1]:
                print(n - i + 1)
                return 0
            print(n - i)
            return 0
    
main()