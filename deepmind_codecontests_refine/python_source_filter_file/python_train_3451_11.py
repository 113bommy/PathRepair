n = int(input())
b = bin(n)[2:]
l = len(b)
ans = []

k = 0
#print(int(b, base=2))
for i in range(40):
    if i//2 == 0:
        if '0' in b:
            ans.append(str(l-b.index('0')))
            b = bin(int(b, base=2)^(2**int(ans[-1])-1))[2:]
        else:
            break
    else:
        if '0' in b:
            b = bin(int(b, base=2)+1)[2:]
        else:
            break
    k+=1
print(k)
print(' '.join(ans))