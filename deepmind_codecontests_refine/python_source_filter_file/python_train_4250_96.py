a,b,k=[int(s) for s in input().split()]

c=[]
for i in range(1,101):
    if a%i==0 and b%i==0:
        c = c+[i]
print(c)
print(c[-k])