n,t = (int(x) for x in input().split())
for i in range(10**(n-1),10**n-10**(n-1)):
    if i%t==0:
        print(i)
        break
else:
    print("-1")
