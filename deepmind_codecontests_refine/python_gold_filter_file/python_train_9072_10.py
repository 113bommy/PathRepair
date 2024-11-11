# cook your dish here
n=int(input())
if n==1:
    print(1)
    print("1 1")
    exit(0)
i=1
while(2*(i-1)<(n-1)):
    i+=1
print(i)

print("1 1")
n-=2
if n>0:
    for j in range(2,i+1):
        print("1"+" "+str(j))
        n-=1
        if n==0:
            break

if n>0:
    for j in range(2,i):
        print(str(i)+" "+str(j))
        n-=1
        if n==0:
            break
        
print(str(i)+" "+str(i))