a1 = "qwertyuiop"
a2 = "asdfghjkl;"
a3 = "zxcvbnm,./"

q = input()
s = input()
p = ""
if q== "R":
    for i in s:
        if i == a1[0] or i == a2[0] or i == a3[0]:
            p = p + i

        if i in a1:
            t = a1.index(i)
            
            p = p + a1[t-1]
        elif i in a2:
            t = a2.index(i)
            
            p = p + a2[t-1]
        elif i in a3:
            t = a3.index(i)
            
            p = p + a3[t-1]
if q == "L":
    
    for i in s:
        if i == a1[9] or i == a2[9] or i == a3[8]:
            p = p + i
        if i in a1:
            t = a1.index(i)
            p = p + a1[t+1]
        elif i in a2:
            
            t = a2.index(i)
            p = p + a2[t+1]
        elif i in a3:
            t = a3.index(i)
            p = p + a3[t+1]
print (p)
