n = int(input())

def fact(n):
    if(n==0 or n==1): return 1
    return n*fact(n-1)

a = fact(n)
b = fact(n/2)
c = fact(n/2-1)

print( (a/(2*b*b)) * (c*c) ) 