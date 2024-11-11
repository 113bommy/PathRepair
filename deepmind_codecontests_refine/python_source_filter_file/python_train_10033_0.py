def prime_cofactor(n):
    lst = []
    for i in range(2,int((n)**0.5)+1):
        if n%i == 0:
            if not i in lst:
                lst.append(i)
            while n%i == 0:
                n = n//i
            if len(prime_cofactor(n)) == 0 and not n in lst:
                lst.append(n)
    if 1 in lst:
        lst.remove(1)
    return lst
        
def total(n):
    count=0
    for i in range(2,n+1):
        if len(prime_cofactor(i))==2:
            count+=1
            print(i)
    return count
#print(prime_cofactor(12))    
n = int(input())
print(total(n))