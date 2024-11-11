def stuff(n):
    n=n+1
    if n-1==0:
        return(0)
    elif n%2==0:
        return(n//2)
    else:
        return(n)
print(stuff(int(input())))