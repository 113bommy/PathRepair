t =int(input())
a= input()
b= input()
sum =0
for i in range(t):
    m,n = float(a[i]),float(b[i])
    if abs(m-n) > (m+n)/2:
        
        sum += min(abs(m-n),9-max(m,n)+min(m,n)+1)
        
    else:
        sum += abs(m-n)
    #print(sum)
print(sum)
    