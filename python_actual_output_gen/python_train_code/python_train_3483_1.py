def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().split())
def msi(): return map(str,input().split())
def li(): return list(mi())

t=ii()
for _ in range(t):
    a,b = mi()
    
    if b==a:
        print(0)
        
    elif a>b:
        if (a-b)%2==0:
            print(1)
            
        else:
            print(2)
            
    else:
        if (b-a)%2==1:
            print(1)
            
        else:
            print(min(3,b-a))
    
    