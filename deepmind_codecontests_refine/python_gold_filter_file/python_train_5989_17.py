z=[];s=0;import math;k=0
for _ in " "*int(input()):
    k=input();a=k.count("C")
    for i in range(len(k)):
        if k[i]=="C":z=z+[i]
    s=s+((math.factorial(a))//(math.factorial(abs(a-2))*2))
for i in range(len(k)):s=s+(math.factorial(z.count(i))//(math.factorial(abs(z.count(i)-2))*2))
print(s)