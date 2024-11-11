n = int(input())

for i in range(n):
    n,k,d = list(map(int, input().split()))
    a = input().split()
    menor = float('inf')
    for i in range(n-d+1):
        elm = len(set(a[i:i+d]))
        if elm < menor:
            menor = elm
    print(menor)
