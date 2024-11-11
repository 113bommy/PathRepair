#dj 16D8101012J ito jun
import sys
def search(a,b):
    na=len(a)
    nb=len(b)
    array = [[0]*(nb+1) for _ in range(na+1)]
    for i,x in enumerate(a,1):
        prerow=array[i-1]
        row=array[i]
        for j,y in enumerate(b,1):
            if x == y:
                row[j]=prerow[j-1]+1
            elif prerow[j] < row[j-1]+1:
                row[j] = row[j-1]
            else:
                row[j] = prerow[j]
    return array[-1][-1]

n = int(input())
strs = [list(i) for i in sys.stdin.read().splitlines()]
result = [search(strs[i*2], strs[i*2+1]) for i in range(n)]
print(*result, sep="\n")

