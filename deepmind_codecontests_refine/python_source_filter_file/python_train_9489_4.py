n = int(input())
tab = list(map(int, input().split()))
maximum = 0

def fonc(indexA, indexB):
    global maximum
    if indexB < indexA:
        return 0
    if tab[indexA:indexB] == sorted(tab[indexA:indexB]):
        maximum = max(maximum, indexB - indexA)
        return 
    fonc(indexA, (indexA+indexB)//2)
    fonc((indexA+indexB)//2 + 1, indexB)

fonc(0, n)
print(maximum)