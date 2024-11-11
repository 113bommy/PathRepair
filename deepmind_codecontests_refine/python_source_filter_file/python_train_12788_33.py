A,B,C,D,E,F = map(int,input().split())
a = 0
x = 1
y = 0
for n in range(30):
    for m in range(30):
        if n*100*A+m*100*B>F:continue
        c = (n*A+m*B)*E
        d = F-100*(n*A+m*B)
        for k in range(min(c,d)+1):
            for l in range(min(c,d)+1):
                if k*C+l*D>(n*A+m*B)*E or n*100*A+m*100*B+k*C+l*D>F:continue
                if x*(k*C+l*D)>y*(n*100*A+m*100*B+k*C+l*D):
                    x = n*100*A+m*100*B+k*C+l*D
                    y = k*C+l*D
                    a = y/x
print(x,y)