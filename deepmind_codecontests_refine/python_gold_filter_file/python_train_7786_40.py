S = int(input())
X2 = 10**9
Y2 = 1
X3 = (X2-(S%X2))%(10**9)
Y3 = (S+X3)//X2
print(0,0,X2,Y2,X3,Y3)