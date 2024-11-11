n,m,k = list(map(int, input().split(" ")))
l = True
if k%2 == 0:
    l = False
    d = k/2
else:
    d = (k+1)/2

col = int(((d-1)%m) +1)
row = int(((d-1)//3)+1)

if l:
    print(str(row), str(col), "L")
else:
    print(str(row), str(col), "R")

