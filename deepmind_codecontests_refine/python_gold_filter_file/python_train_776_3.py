import math as m

n = int(input())
ans =[]
while n:
    t = 0
    for i in range(len(str(n))):
        if (n//(10**i))%10:
            t+=10**i
            # print(t)
    ans.append(str(t))
    n-=t
print('{0}\n{1}'.format(len(ans), ' '.join(ans)))