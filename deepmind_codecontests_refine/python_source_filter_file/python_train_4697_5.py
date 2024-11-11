a, b, c = input().split()
a = int(a)
b = int(b)
c = int(c)
count = 0
if a+b>c and a+c>b and b+c>a:
    print(count)
else:
    if a+b <= c:
        count += c - (a+b) + 1
        #if a<b:
            #count = count - a
        #else:
            #count = count - b
    elif a+c <= b:
        count += b - (a+c) + 1
        #if a<c:
            #count = abs(count - a)
        #else:
            #count = abs(count - c)
        
    elif b+c < a:
        count = a - (b+c) + 1
        #if b<c:
            #count = abs(count - b)
        #else:
            #count = abs(count - c)
    print(count)