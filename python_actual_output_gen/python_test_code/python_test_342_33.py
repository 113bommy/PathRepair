n=int(input())
x=0
for i in range(1,n):
    x+=i*(i-1)/2
    if x>n:
        print(i-1)
        break
