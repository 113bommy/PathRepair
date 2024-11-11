X=int(input())

for i in range(X+1,X*2):
    ok=0
    for j in range(2,i):
        if i%j == 0:
            ok += 1
    if ok == 0:
        print(i)
        break