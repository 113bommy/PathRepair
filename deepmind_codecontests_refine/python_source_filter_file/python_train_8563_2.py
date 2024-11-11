#A-Numbrs 

a = int(input())
results = 0
for i in range(2,a):
    t= a
    while t>0:
        results += t%i
        t = t//i
x=results
y =a-2

while y>0:
    #for GCD
    x,y = y,x%y
print(f"{int(results/x)} {int((a-2)/x)}")