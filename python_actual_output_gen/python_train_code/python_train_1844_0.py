def ans(n):
    x = n//2
    if n%2 == 0:
        return (str(x)+' '+str(x))

    a = 1
    for i in range(2, int(n**0.5)+1):
        if n%i == 0:
            a = i
            break
    if a == 1: return ('1'+str(n-1))
    
    p = n//a
    q = n-p
    return (str(p)+' '+str(q))

for _ in range(int(input())):
    n = int(input())
    print(ans(n))