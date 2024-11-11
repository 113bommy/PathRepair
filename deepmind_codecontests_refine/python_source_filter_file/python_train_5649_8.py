import math
wqr = int(input())
for er in range(wqr):
    a = list(input())
    temp = []
    for i in range(len(a)):
        if(i==0):
            if(a[i]=='+'):
                temp.append(1)
            else:
                temp.append(-1)
            continue
        if(a[i]=='+'):
            temp.append(temp[i-1]+1)
        else:
            temp.append(temp[i-1]-1)
    i = 0
    ans = 0
    print(temp)
    for j in range(len(a)+1):
        print(i,"  ",ans)
        if(j+temp[i]<0):
            ans+=i+1
        else:
            while i<len(a):
                if(j+temp[i]<0):
                    break
                else:
                    i+=1
            if(i<len(a)):
                ans+=i+1
            else:
                ans += i
        if(i>=len(a)):
            break
    print(ans)