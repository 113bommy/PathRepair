l = []

s = ""

n = int(input())
a, b = 1,1
l.append(a)
l.append(b)
count = 0
if n == 1:
    print("O")
elif n == 2 :
    print("OO")
else:
    while count < n-2:
        c = a + b
        a = b
        b = c
        count+=1
        if c <= n:
            l.append(c)
#print(l)

    for i in range(1,n+1):
        if i in l:
        #print(type(i))
            s = s+"O"
        else:
            s = s+"o"
#print(l2)
    print(s)
