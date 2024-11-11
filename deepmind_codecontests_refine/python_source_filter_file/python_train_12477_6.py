X=int(input())
i=0
d=0
for i in range(X):
    d+=i
    if d>=X:
        print(i)
        exit()