fib=[1,1]
for i in range(2,1009):
    fib.append(fib[-1]+fib[-2])
n=int(input())
ans=''
for i in range(1,n+1):
    if i in fib:
        ans+='0'
    else:
        ans+='o'
print(ans)