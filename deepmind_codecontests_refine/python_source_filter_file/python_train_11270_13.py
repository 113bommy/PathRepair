t=int(input())
for _ in range(t):
    n=int(input())
    l=list(map(int, input().split()))
    Fin=False
    for i in range(n-1):
        if l[i]<l[i+1]:
            break
        if i==n-2:
            Fin=True
            print("No")
    for j in range(i, n-1):
        if Fin:
            break
        if l[j]>l[j+1]:
            Fin=True
            print("Yes")
            print(i+1, i+2, j+2)
            break
    if not Fin:
        print("No")