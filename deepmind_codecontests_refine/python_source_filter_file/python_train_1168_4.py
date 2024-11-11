t = int(input())

for _ in range(t):
    a, b, p = map(int, input().split())
    s = [i for i in input()]
    n = len(s)
    
    c = [0]*n
    
    sw = s[0]
    c[0] = (a if sw == "A" else b)
        
    for i in range(n-1):
        if s[i] == "A" and sw == "B":
            sw = "A"
            c[i] = a
        elif s[i] == "B" and sw == "A":
            sw = "B"
            c[i] = b
    
    f = False
    
    for i in range(n-2, -1, -1):
        if p < c[i]:
            j = i+1
            while c[j] == 0 and j < n-2:
                j += 1
            print(j+1)
            f = True
            break
            
        p -= c[i]
    
    if not f:
        print(1)