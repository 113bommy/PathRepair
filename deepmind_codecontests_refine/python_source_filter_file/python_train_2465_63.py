n= int(input())
L=list(map(int,input().split()))
L.sort()
print(L[int(n/2)])