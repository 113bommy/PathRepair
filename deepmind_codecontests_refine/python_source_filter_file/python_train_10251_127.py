x=int(input())
if x%2==0:
    s=x//2*(x//2+1)-x//2*x//2
    print(s)
else:
    x=x+1
    s=x//2*x//2-x//2*(x//2+1)
print(s)