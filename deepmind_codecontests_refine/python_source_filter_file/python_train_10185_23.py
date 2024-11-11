a,b,c,x=[int(input()) for i in range(4)]
i=0
for i in range(a+1):
    for j in range(b+1):
        for k in range(c+1):
            if 500*a+100*b+50*c==x:
                i+=1
print(i)