N=int(input())
X=input()
num_X = int(X, base=2)
pop_x = X.count("1")
if pop_x <= 1:
    mod0 = pop_x + 1
    res0 = num_X % mod0
else:
    mod1 = pop_x - 1
    mod0 = pop_x + 1
    res1 = num_X % (mod1)
    res0 = num_X % (mod0)

# pops = [0]*(N+20)
for i in range(N):
    tmp = 0
    if X[i] == "0":
        # +
        tmp = (res0 + pow(2, N-i-1, mod0))%mod0
    else:
        if pop_x == 1:
            print(0)
            exit()
        tmp = (res1 - pow(2, N-i-1, mod1))%mod1
    
    if tmp == 0:
        print(1)
        continue
    cnt = 1
    while tmp != 0:
        pop = bin(tmp).count("1")
        tmp %= pop
        cnt += 1
    print(cnt)