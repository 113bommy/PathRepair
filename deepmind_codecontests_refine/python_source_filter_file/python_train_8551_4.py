def gcd(a,b): 
    if a == 0: 
        return b 
    return gcd(b % a, a)
    
def lcm(a,b): 
    return (a*b) / gcd(a,b)

arr = input()
A,B = [int(x) for x in arr.split(' ')]

d = abs(A-B)

divisiors = []

for i in range(1,100000):
    if i*i>d:
        break
    else:
        if d%i==0:
            divisiors.append(i)
            divisiors.append(d//i)
            
#print(len(divisiors))
#quit()
mini = -1
res = 0
for div in divisiors:
    new_A = A//div
    if A%div!=0:
        new_A += 1
    new_A = new_A*div
    
    new_B = B//div
    if B%div!=0:
        new_B += 1
    new_B = new_B*div
    
    L = lcm(new_A,new_B)
    print(new_A,new_B,L)
    if mini==-1:
        mini = L
        res = new_A - A
    elif L<=mini:
        if L==mini:
            res = min(res,new_A - A)
        else:
            res = new_A - A
        mini = L
        
print(res)