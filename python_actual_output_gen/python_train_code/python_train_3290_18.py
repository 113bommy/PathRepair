n = int(input())

I = False

for i in range(n):
    h, s, e= input().split()
    s, e = int(s), int(e)
    if s >= 2400 and e >= s:
        I = True
        break
    
if I:
    print("YES")
else:        
    print("NO")