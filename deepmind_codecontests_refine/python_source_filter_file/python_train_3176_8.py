s=input().split()
n=int(s[0]);t=int(s[1]);pd=0
for i in range(10**n,10**(n+1)):
    if i%t==0:
        print(i)
        pd=1
        break
if pd==0:
    print(-1)