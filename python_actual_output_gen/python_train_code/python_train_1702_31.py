A = input().split()
B = input().split()
Aarray = [int(x) for x in list(B)]
Aarray = sorted(Aarray)
d = Aarray[int(A[1])] - Aarray[int(A[2])]
print(d)