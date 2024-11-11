a=input()
n=len(a)//2
#print(a[:n],a[len(a):n:-1])
if a[:n]==a[len(a):n:-1]:
    print(a)
else:
    print(a+a[len(a):0:-1]+a[0])