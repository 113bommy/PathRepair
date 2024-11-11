def solve(L,R,k):
    #print(*[(bin(x)[2:]).zfill(max([len(bin(y)[2:]) for y in [L,R]])) for x in [L,R]],sep='\n')
    if k < 5:
        if k==1:
            return [L]
        elif k==2:
            if R-L+1==2:
                if L < (L^R):
                    return [L]
                else:
                    return [R]
            else:
                if L&1:
                    return [L+1,L+2]
                else:
                    return [L,L+1]
        else:
            b = 60
            while (L&(1<<b))==0 and (R&(1<<b))==0:
                b -= 1

            if L==1:
                return [1,2,3]
            elif k==3:
                if (L&(1<<b))==(R&(1<<b)):
                    return solve(L,R,2)
                else:
                    r = b
                    while (L&(1<<r))==0:
                        r -= 1

                    if (1<<b)+(1<<r) <= R:
                        return [L,(1<<b)+(1<<r),(1<<b)+((1<<r)^L)]
                    else:
                        return solve(L,R,2)
            else: #k==4
                if (L^1)&1:
                    return [L,L+1,L+2,L+3]
                elif L+4 <= R:
                    return [L+1,L+2,L+3,L+4]
                else:
                    return solve(L,R,3)
    else:
        if L&1:
            return [L+1,L+2,L+3,L+4]
        else:
            return [L,L+1,L+2,L+3]

ans = solve(*map(int,input().split()))
xor = 0
for x in ans:
    xor ^= x
print(xor)
print(len(ans))
print(*ans)
