# cook your code here

n, l, a = map(int, input().split(' '))

tpi, lpi = 0, 0
output = 0

for _ in range(n):
    
    ti, li = map(int, input().split(' '))
    
    if tpi+lpi == ti:
        tpi = ti
        lpi = li
        continue
    else:
        
        dist = ti - tpi+lpi
        output += dist//a
        tpi = ti
        lpi = li
        
output += (l - (tpi+ lpi))//a
    
print(output)