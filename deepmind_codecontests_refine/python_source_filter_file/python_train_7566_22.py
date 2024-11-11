n=int(input())
a=input()
for i in range(2,n):

    if n%i==0:
        print(i,a)
        #print(a[])
        a=a[i-1::-1]+a[i:]
        #print(i,a)
a=a[::-1]
print(a)
