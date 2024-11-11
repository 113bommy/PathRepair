n=int(input());
x=[int(x) for x in input().split()]
for i in range(n):
    if x[i]==max(x):
        p=i
        break
for i in range(1,n+1):
    if x[-i]==min(x):
        q=i-1
        break
if(p<(n-q+1)):
    print(p+q)
else:
    print(p+q-1)

