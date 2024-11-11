n,m = input().split()
k=int(n)
li = list(input().split())

for i in range(k,10000):
    for e in li:
        if e in str(i):
            break
    else:
        print(i)
        break