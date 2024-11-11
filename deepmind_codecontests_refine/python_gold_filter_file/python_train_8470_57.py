def calc(y):
    while True:
        t = y
        s = []
        while t > 0:
            s.append(t%10)
            t//=10
            #print(s) 
        if len(s) == len(set(s)):
            return y
        y+=1

y = int(input())
print(calc(y+1))




