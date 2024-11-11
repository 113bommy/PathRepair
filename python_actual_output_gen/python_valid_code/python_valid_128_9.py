n=input()
L=['H','Q','9','+']
p='NO'
for k in range(0,len(L)):
    if(L[k] in n):
        p='YES'
        break
print(p)
