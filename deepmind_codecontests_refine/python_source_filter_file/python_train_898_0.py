L = input().split()
n = int(L[0])
scnt = hcnt = 0
for i in range(0, n):
    L = input().split(' ')
    if L[1]=="soft":
        scnt+=1
    else:
        hcnt+=1
for i in range(1, n*n):
    if scnt<=(i*i+1)/2 and hcnt<=(i*i+1)/2 and scnt+hcnt<=i*i:
        print(i)
        break