def product(n):
    x = 1
    for i in n:
        if i < 0:
            x = x*(-1)
   # print(x)
    return(x)
op = 0
pm = False
m = int(input())
n = input()
n = n.split(" ")
for i in range(len(n)):
    n[i] = int(n[i])

if product(n)<=0:
    pm = True

for i in range(len(n)):
    if n[i]<-1:
        op += -1 - n[i]
    #    n[i] = -1
        
        print(op)
    elif n[i] == 0 and not pm:
        op += 1
    #    n[i] = 1
        
        print(op)
    elif n[i]>1:
        op += n[i] - 1
    #    n[i] = 1
    elif n[i] == 0 and pm:
        n[i] = -1
        op += 1
        
        pm = False
    #    print(op)
if product(n)<=0:
    pm = True
if pm == True:
    for i in range(len(n)):
        if n[i]<=0 and pm:
            
            op += 1 - n[i]
            n[i] = 1
    #        print(op)
            pm = False
        
            
print(op)