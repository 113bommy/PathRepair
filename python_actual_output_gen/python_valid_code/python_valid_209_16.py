n, p, k = map(int, input().split())

lB = max(1, p - k)
rB = min(n, p + k)
if lB != 1: print("<< ", end="")

for i in range(lB, rB + 1):
    if i != p:
        print(i, end= " ")
    else:
        print("(" + str(i) + ") ", end= '')
        
if lB != n:
    print(">>")        
    
    