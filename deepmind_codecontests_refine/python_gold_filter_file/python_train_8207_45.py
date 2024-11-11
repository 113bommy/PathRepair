X = int(input())
k = (X//11) * 2
l = X%11
if l == 0:print(k)
elif l <= 6:print(k+1)
else:print(k+2)