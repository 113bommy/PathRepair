def gcd_hell():
    print("hello")

def gcd(a,b):
    if(b==0):
        return a
    a%=b
    return gcd(b,a)
    


a,b,c=map(int,input().split())
y=0

res = gcd(a,b)

if(c>res): res = c%res + res

while (c-b*y)/a >=0:
    if (c-b*y)%a ==0:
        print('Yes')
        break
    y += 1
else:
    print('No')
