


a  = int(input())

t = list(map(int,input().split()))


p=0


for k in range(a):
    if k==0:
        p+=t[k]
    else:
        if t[k]!=t[k-1]:
            p+=abs(t[k]-t[k-1])

print(p)
