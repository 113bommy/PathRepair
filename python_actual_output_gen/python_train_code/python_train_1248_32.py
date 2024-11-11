import sys

def equator(n,arr):
    nbrp = sum(arr)
    if nbrp/2 != 0:
        nbrp = nbrp+1 
    np = 0
    for i in range (len(arr)):
        np  = np+  arr[i]
        if np == int(nbrp/2):
            return i+1 
    
    return n

if __name__ == "__main__":
    n = int(input().strip())
    arr = [int(x) for x in input().split()]
    print(equator(n,arr))