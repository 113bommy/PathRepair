n=int(input())
ans=[]
for i in range(n//2):
    ans+=[str(i+1)]
    ans+=[str(n-i)]
if n!=3 and n%2:
    ans+=[str(n//2+1)]
if n==1 or n==2: print('\n'.join(['1','1']))
if n==3:
    print(2)
    print(ans[-1],' '.join(ans[:-1]))
else:
    print(n)
    print(ans[-1],' '.join(ans[:-1]))