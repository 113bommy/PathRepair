a = input()
k = a.count('VK')
b = False
while len(a)!=0:
    n = a.find('VK')
    if n == -1:
        r = a
        a = ''
    else:
        r = a[:n+1]
        a = a[n+2:]
    if (r.find('VV')!=-1 or r.find('KK')!=-1) and b == False:
        b = True
        k+=1
print(k)