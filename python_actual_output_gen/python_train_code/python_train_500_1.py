def gcd(a,b):
    if a == 0:
        return b
    return gcd(b % a, a)
 
# Function to return LCM of two numbers
def compute_lcm(a,b):
    return (a / gcd(a,b))* b
n,m=list(map(int,input().split()))
lcm=compute_lcm(n,m)
fa=lcm/n
fb=lcm/m
if fa>fb : 
    fb+=1 
else:
    fa+=1
if(fa>fb):
    print("Dasha")
elif(fa<fb):
    print("Masha")
else:
    print()
