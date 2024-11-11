import math
for _ in range(int(input())):
    n=int(input())
    flag=0
    for i in range(2,math.ceil(math.sqrt(n))+1):
        l=[]
        if n%i==0:
            l.append(i)
            a=n//i
            for j in range(2,math.ceil(math.sqrt(a))+1):
                if n%j==0 and j!=l[-1]:
                    l.append(j)
                    break
            if len(l)<2:
                continue
            b=n//(l[0]*l[1])
            if b!=l[0] and b!=l[1] and b!=1:
                l.append(b)
                print("YES")
                print(*l)
                flag=1
                break
            else:
                continue
    if flag==0:
        print("NO")