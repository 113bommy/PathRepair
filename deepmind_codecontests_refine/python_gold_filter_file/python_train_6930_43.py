def generarM(n):
    if (n%2==0) and (n!=1000):
        return n+2
    if n==1000:
        return n-2
    else:
        return 3


print(generarM(int(input())))