s=input()
count=0
for i in range(2**(len(s)-1)):
    t=""
    for j in s:
        t+=j
        if i%2==1:
            t+="+"
        i//=2
    print(t)
    count+=eval(t)
print(count)
