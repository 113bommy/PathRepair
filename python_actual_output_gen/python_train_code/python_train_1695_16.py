alphabet = 'abcdefghijklmnopqrstuvwxyz'
tc = int(input())
for i in range(tc):
    n,a,b = (int(i) for i in input().split())
    l = []
    j = 1
    for i in range(n):
        if(j>b or j>=26):
            j = 1
        if(j<=b):
            l.append(j)
            j+=1

    #print(l)
    s = ''
    for i in range(n):
        s+=alphabet[l[i]-1]
    print(s)