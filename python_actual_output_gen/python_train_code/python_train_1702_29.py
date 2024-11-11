n,a,b = tuple(map(int, input().strip().split()))
h = list(map(int, input().strip().split()))

def insertionsort(lst):
    for i in range(1,len(lst)):
        
        val = lst[i]
        
        for j in range(0, i):
            if lst[j] > val:
                tmp = lst[j]
                lst[j] = val
                val = tmp

        lst[i] = val
        
    return lst


h = insertionsort(h)


print(abs(h[a]-h[b]))