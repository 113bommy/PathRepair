n=int(input())
a=input()
for i in range(1,n+1):
    if n==((i*(i+1))//2):
        t=i
        break
for j in range(t):
    print(a[j*(j+1)//2],end="")
print()
    
    
