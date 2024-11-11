def TPrimes(n,arr):
    l = [1]*1000001
    l[0] = 0
    l[1] = 0
    limit = int(1000001**(1/2))
    for i in range(2,limit):
        if l[i] == 1:
            k = i
            while k+i <= 1000000:
                k += i
                l[k] = 0
    for i in arr:
        ok = int(i)**(1/2)
        if ok == int(ok):
            if l[int(ok)] == 1:
                print("YES")
            else:print("NO")
        else:
            print("NO")
n = int(input())
arr = list(map(int,input().split()))
TPrimes(n,arr)
