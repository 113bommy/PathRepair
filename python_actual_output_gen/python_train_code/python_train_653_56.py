n = int(input())
L = list(map(int, input().split()))

L.sort(reverse=Ture)
print(sum(L[0::2]) - sum(L[1::2]))