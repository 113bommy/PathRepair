n=int(input())
fibl=[0,1]
def fib(x):
    if x<len(fibl):
        return fibl[x]

    else:
        temp=fib(x-1)+fib(x-2)
        fibl.append(temp)
        return temp

j=0

while True:
    if fib(j)==n:
        break
    j=j+1
if n==1:
    print(0,0,1)
elif n==0:
    print(0,0,0)
else:
    print(0,fibl[j-2],fibl[j-1])
