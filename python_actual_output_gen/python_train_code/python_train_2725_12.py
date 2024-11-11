n=int(input())
x=[]
y=[]
for i in range(n):
    s=input().split(' ')
    x.append(int(s[0]))
    y.append(int(s[1]))
nof=0
for i in range(n):
    f1=0
    f2=0
    f3=0
    f4=0
    for j in range(n):
        if x[i] == x[j] and y[i] > y[j]:
            f1=1
        if x[i] == x[j] and y[i] < y[j]:
            f2=1
        if y[i] == y[j] and x[i] > x[j]:
            f3=1
        if y[i] == y[j] and x[i] < x[j]:
            f4=1
        if f1+f2+f3+f4 == 4:
            nof+=1
print(nof)