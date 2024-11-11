n= list(map(int,input().split()))
n[0] 
k = n[1]
a = list(map(int,input().split()))
dicta = {}
dictb = {}
for j in a:
    if j in dicta:
        dicta[j]+=1
    else:
        dicta[j]=1
    if j not in dictb:
        dictb[j] = 0  
b=0
for j in dicta:
    if dicta[j]>=k:
        b=1
        break
if b==1:
    print(0)
else:
    minimum = 2*10**5
    for i in range(20):
        tmp = []
#         print(a)
        for l in a:
            j = l//2
            if j in dicta:
                dicta[j]+=1
                dictb[j]+=i+1
                if dicta[j]>=k:
                    if dictb[j]<minimum:
                        minimum =dictb[j]
            elif j>0:
                dicta[j]=1
                dictb[j]=i+1
            tmp.append(j)
        a = tmp
        for j in dicta:
            if dicta[j]>=k:
                if dictb[j]<minimum:
                    minimum =dictb[j]
    print(minimum)