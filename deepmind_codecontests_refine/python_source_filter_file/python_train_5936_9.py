q = int(input())

def lcss(x,y):
    
    lcs = [0]*(len(x)+1)
    for i in range(len(y)):
        w1 = y[i]
        lcs_2 = lcs[:]
        for j in range(len(x)):
            if x[j] == w1:
                lcs[j+1] = lcs_2[j] + 1  
            elif lcs[j+1] < lcs[j]:
                lcs[j+1] = lcs[j]
    return lcs[-1]

ret = []
for i in range(q):
    x = input()
    y = input()
    ret.append(lcss())
print(*ret,sep= "\n")