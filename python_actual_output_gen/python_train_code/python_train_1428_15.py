n = int (input())
k = 1
s = ''
b = 0
c = 0
d = []
while k<100:
    if n>k:
        a = n-k
    
        s = str(a)
        for i in range(len(s)):
                  b+=int(s[i])
              
        if a+b == n:
                    c+=1   
                    d.append(a)
    k+=1
    s = ''
    b = 0
print(c)
print('\n'.join(str(v) for v in d))
            
