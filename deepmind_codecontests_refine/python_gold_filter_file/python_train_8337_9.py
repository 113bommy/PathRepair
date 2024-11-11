(n,k) = map(int,input().split())
t = input()
startIndex = 0
for i in range(1,n+1):
    startIndex = i
    fined = True
    for j in range(0,n-i):
        if t[j] != t[j+i]:
            fined = False
            break
    if fined:
        break
#print(startIndex)
if n == 1:
    print(t[0]*k)
else:
    print(t[0:(n-startIndex)] + t[(n-startIndex):n]*k)


