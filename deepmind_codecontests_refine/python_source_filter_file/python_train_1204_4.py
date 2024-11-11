

if __name__ == "__main__":
    N = int(input())
    lst2 = list(map(int, input().split()))
    M = max(lst2)
    N=M

    lst = [True for _ in range(N+100)]
    lst[0] = False
    lst[1]= False

    i = 2
    while i < N:
        if lst[i]:
            for j in range(2,1+(N-1)//i):
                lst[i*j]=False
        i += 1

    primes=[i for i in range(N) if lst[i]]
    #print(len(re))






    auxlst = [0]*(M+1)
    for i in lst2:
        auxlst[i] += 1

    result = [0]*(M+1)









    for p in primes:
        if p > M:
            break
        n=p
        for _ in range(M//p):
            result[p] += auxlst[n]
            n += p

    result = max(1,max(result))
    print(result)
    # to make changes
