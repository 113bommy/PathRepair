
def tavas(n):
    s=str(n)
    l=len(s)
    s_i=(2**l)-1
    #s_n=int("4"*l)
    for i in range(l):
        if s[i]=="7":
            s_i+=2**i
    return s_i

k=int(input())
print(tavas(k))