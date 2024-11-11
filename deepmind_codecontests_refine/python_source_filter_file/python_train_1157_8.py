# alpha = "abcdefghijklmnopqrstuvwxyz"
t = 1#int(input())
for test in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 100000

    for i in range(1,n+1):
        tmp = 0
        for j in range(1, n+1):
            tmp = tmp+(2*abs(j-i)+j-1+i-1+i-1+j-1)*a[j-1]

        if tmp<ans:
            ans = tmp

    print(ans)




   