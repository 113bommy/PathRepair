n = int(input())
lista = list(map(int, input().split()))
lista.sort()
ans = False
for i in range(n-2):
    if lista[i] + lista[i+1] > lista[i+2]:
        ans = True
if ans:
    print("YES")
else:
    print("NO")
