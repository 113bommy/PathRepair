n=int(input())
if n==0:
    print(0,0,0)
elif n==1:
    print(1,0,0)
else:
    fib=[0,1,1,2]
    while n not in fib:
        fib.append(fib[-1]+fib[-2])
    print(fib[-4],fib[-3],fib[-3])