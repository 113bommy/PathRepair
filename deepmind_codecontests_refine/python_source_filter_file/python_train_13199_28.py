a=input()
a=int(a)
c=1
b=round(a*0.5)+2
for n in range(1,b):
    if a%n==0:
        c=n
d=a/c
print(d+c-2)