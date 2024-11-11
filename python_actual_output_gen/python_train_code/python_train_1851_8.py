a = list(input()); b = list(input())
c = sorted(a); d = sorted(b); k = 0
if c != d or len(a) != len(b):
    print("NO")
else:
    for i in range(len(a)):
        if a[i] != b[i]: k+=1
    if k == 2: print("YES")
    else: print("NO",k)