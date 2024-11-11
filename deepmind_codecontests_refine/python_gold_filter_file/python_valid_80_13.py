for _ in range(int(input())):
    n = int(input())
    s = input()
    k = int(n//2)
    done = False
    for i in range(k, n):
        if(s[i] == "0"):
            print(1, i+1, 1, i)
            done = True
            break
    if(not done):
        if(n&1):
            print(k+1, n-1, k + 2, n)
        elif(s[k-1] == "1"):
            print(k, n-1, k+1, n)
        else:
            print(k, n, k+1, n)