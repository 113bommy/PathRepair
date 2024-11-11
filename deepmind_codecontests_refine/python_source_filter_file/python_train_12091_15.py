nmk=[int(x) for x in input().split()]
values=[int(x) for x in input().split()]
def emotes(lista1, lista2):
    m=lista1[1]
    k=lista2[2]
    index_max=lista2.index(max(lista2))
    max1=max(lista2)
    del lista2[index_max]
    max2=max(lista2)
    #print(max_)
    #print(two_max)
    """
    if k>=m:
        return max1*m
    else:
    """
    return (int(m/(k+1))*(max1*k+max2)+(m%(k+1))*max1)
print(emotes(nmk, values))