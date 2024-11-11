import math
def lcm(a,b):
    return (a*b)//math.gcd(a,b) 
n=int(input())
s=input()
e=input()
l=lcm(len(s),len(e))
k=n%l
w=0
w1=0
ex=0
ex1=0
for i in range(l):
    if s[i%len(s)]==e[i%len(e)]:
        w1=w1
        w=w
    elif s[i%len(s)]=='R' and e[i%len(e)]=='P':
        w1+=1
    elif s[i%len(s)]=='S' and e[i%len(e)]=='P':
        w+=1
    elif s[i%len(s)]=='R' and e[i%len(e)]=='S':
        w+=1
    elif s[i%len(s)]=='P' and e[i%len(e)]=='S':
        w1+=1
    elif s[i%len(s)]=='P' and e[i%len(e)]=='R':
        w+=1
    elif s[i%len(s)]=='S' and e[i%len(e)]=='R':
        w1+=1
    #print(k,i)
    if i==k-1:
        ex=w
        ex1=w1
#print(w,w1) 
cou=n//l
w*=cou
w1*=cou
w+=ex
w1+=ex1
print(w1,w)
    