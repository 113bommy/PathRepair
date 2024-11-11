from math import factorial as fact
n = int(input())
a = []
k = 0
for i in range(n):
    b = input()
    c = b.count('C')
    if c >= 2:
        k += fact(c)/(2*fact(c-2))
    a.append(b)
for i in range(n):
    t = 0
    for j in range(n):
        if a[j][i] == 'C':
            t += 1
    if t >= 2:
        k += fact(t)/(2*fact(t-2))
print(int(k))

    
            
        
