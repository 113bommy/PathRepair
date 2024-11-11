a = list(input())
b = list(input())
s = list()
for j in range(len(a)): 
    if int(a[j]) == int(b[j]):  
        s.append('0')
    else:  
        s.append('1')
print(*s, sep='')