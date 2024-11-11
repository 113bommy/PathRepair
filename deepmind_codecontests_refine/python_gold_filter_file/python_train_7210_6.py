def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().split())
def li(): return list(mi())
n=ii()
s=0
a=li()
for i in a:
    s+=i
if(n>s):
    n=n%s
if(n==0):
    n+=s
for i in range(7):
    n-=a[i]
    if(n<=0):
        print(i+1)
        break
    