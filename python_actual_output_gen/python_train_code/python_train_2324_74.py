def lucky(n):
    v=0
    for i in range(1,n+1):
        v+=n**i
    return(v)
n= input()
print(lucky(int(n)))