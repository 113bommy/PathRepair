
# x is the number of pillows Frodo wants

def is_ok(x, y):
    
    if y > (x - 1):
        val = (((x-1) * x) >> 1) + y - (x - 1)
    else:
        val = (y * (x - 1 + x - y)) >> 1
        
    return val     


hobbits, pillows, k = [int(x) for x in input().split()]

l = 1 
r = pillows

while l < r:
    m = (l + r) >> 1
    
    valor = is_ok(m, k - 1) + is_ok(m, hobbits - k) + m
    # print(valor, m, l, r)
    
    if valor < pillows:
        l = m + 1
    else:
        r = m - 1

print(l)


