n = int(input())
L = list(map(int,input().split()))
L.sort()

print(sum(L[n:2*n]))