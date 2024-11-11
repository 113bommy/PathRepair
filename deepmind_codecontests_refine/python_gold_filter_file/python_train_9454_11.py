N = int(input())

i = 1
K = []
while(1):
    k = i * (i+1) // 2
    if k > 10**5:
        break
    K.append(k)
    i+=1
if not N in K:
    print ('No')
    exit()
print ('Yes')
S = [[],[]]
i = 0

for n in range(1,N+1):
    S[i].append(n)
    S[-1].append(n)
    i+=1
    if n in K:
        if n==N:
            break
        i = 0
        S.append([])
print(len(S))
for s in S:
    print(str(len(s)) + ' ' + ' '.join(map(str,s)))
