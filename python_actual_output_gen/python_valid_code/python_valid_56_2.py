def s(x):
    x=str(x)
    return sum([int(i) for i in x])
n=int(input())
c=1
k = int(n**0.5)
for i in range(int(n**0.5),max(k-s(n),0),-1):
    if (n/i)==s(i)+i:
        print(i)
        c=0
        break
if c:
    print(-1)