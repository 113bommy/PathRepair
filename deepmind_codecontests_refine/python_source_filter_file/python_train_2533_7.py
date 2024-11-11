def isprime(n):
    if n == 2:
        return(True)
    else:
        i = 2
        while(i*i<=n):
            if n%i == 0:
                return(False)
            i = i+1
        return(True)
n = int(input())
table = [0]*(n+1)
table[1] = 1
for i in range(2,n+1):
    l = int(n**(1/2))
    if isprime(i) == True:
        table[i] = i+1
    else:
        for j in range(2,l+1):
            if i%j == 0:
                table[i] = max(table[i],i+max(table[j],table[i//j]))
print(table[n])
