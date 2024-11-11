a, b = map(int, input().split())
lista = list(map(int, input().split()))
listb = list(map(int, input().split()))

print(lista)
i = 0
j = 0
cnta = 0
cntb = 0

ans = 0

while(i<len(lista) and j < len(listb)):
    
    if(cnta == cntb):
        cnta += lista[i]
        cntb += listb[j]
        ans += 1
        i += 1
        j += 1
    elif cnta < cntb:
        cnta += lista[i]
        i += 1
    elif cnta > cntb:
        cntb += listb[j]
        j += 1
    # print("cnta==" + str(cnta) + ", cntb==" + str(cntb))

print(ans)









