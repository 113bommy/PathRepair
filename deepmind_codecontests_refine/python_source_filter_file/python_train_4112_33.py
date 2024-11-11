#maximum
n =input()
l =len(n)
n = int(n)

def dekh(x):
   # if(x ==0 ):
    #    return 0
    if(x == 1):
        return 9
    x1 =0
    for i in range(1,x):
        x1 = x1 + 9*i*(10**(i-1))
    return x1

ans = dekh(l)

ans = ans + (n - 10**(l-1) + 1)*l
print(ans)