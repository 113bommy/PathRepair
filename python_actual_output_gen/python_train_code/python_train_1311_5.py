inp=input().split()
n=int(inp[0])
x=int(inp[1])
# def factor_pairs(p):    
#     return [((i, p//i) for i in range(1, int(p**0.5) + 1) if p % i == 0 and i<=n and p//i<=n)]
 
# def factors(n):    
#     return set(reduce(list.__add__, 
                # ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))
 
def cnt(p):   
    c=0 
    for i in range(1, int(p**0.5) + 1):
        if p % i == 0 and i<=n and p//i<=n:
            if i==p//i:
                c+=1
            else:
                c+=2
            print(i,"   ",p//i)
    return c
 
print(cnt(x))