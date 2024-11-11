def pizza(n):
    if n%2:
        n+=1
    return int((max(n,6)//2)*5)
    
       

t=int(input())
for i in range(t):
    n=int(input())
    print(pizza(n))
    