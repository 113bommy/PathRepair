N,P = map(int,input().split())
S = input()

if P%2 == 0 or P%5 == 0:
    ans = 0
    S = S[::-1]
    for i,j in enumerate(S):
        if int(j)%P == 0:
            ans += i+1
    print(ans)
else:
    tmp = 0
    mod = [0]*P
    ##mod[0] = 1
    S = S[::-1]
    for i,j in enumerate(S):
        tmp = (tmp + int(j)*pow(10,i,P))%P
        mod[tmp] += 1    
    print(sum([i*(i-1)//2 for i in mod]))