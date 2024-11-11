n, k, x = map(int,input().split())
c0 = list(map(int,input().split()))
max = 0
for i in range (len(c0)-1):
    c = c0[:]
    s = 0
    if c[i]==c[i+1]==x:
        del c[i:i+2]
        s += 2
        possib = True
        while possib:
            if i>0 and i<len(c):
                if 1<i<len(c)-1 and c[i-2]==c[i-1]==c[i]==c[i+1]:
                    del c[i-2:i+2]
                    s += 4
                    i -= 2
                elif 1<i and c[i-2]==c[i-1]==c[i]:
                    del c[i-2:i+1]
                    s += 3
                    i -= 2
                elif i<len(c)-1 and c[i-1]==c[i]==c[i+1]:
                    del c[i-1:i+2]
                    s += 3
                    i -= 1
                else:
                    possib = False
            else:
                possib = False
    if s > max:
        max = s
print(max)
                
            