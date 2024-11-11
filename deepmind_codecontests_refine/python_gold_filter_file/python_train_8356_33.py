def lis():
    return [int(x) for x in input().split()]
    
def intt():
    return int(input())
    
t = intt()
for i in range(t):
    n = intt()
    flag = 0
    for i in range(n//3+1):
        for j in range(n//5+1):
            for k in range(n//7+1):
                if n-i*3-j*5-k*7==0:
                    print(str(i)+" "+str(j) + " "+ str(k))
                    flag=1
                    break
            if flag==1:
                break
        if flag==1:
            break
    if flag==0:
        print(-1)