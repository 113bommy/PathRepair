n,l=map(int,input().split())
A=[int(i) for i in input().split()]

wa=[A[i]+A[i+1] for i in range(n-1)]
lim=max(wa)
knot=wa.index(lim)

go=False
if l<=lim:
    print("Possible")
    go=True
else:
    print("Impossible")
    
if go:
    for i in range(knot):
        print(i+1)
    for i in range(n-knot-2):
        print(n-i-1)
    print(knot+1)
        