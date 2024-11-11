n=int(input())
pow,dir=0,-1
cm=[0]*n
p=list(map(int,input().split()))
while pow!=n:
    dir+=1
    for i in range(n):
        if cm[i]==0 and pow>=p[i]:
            pow+=1
            cm[i]=1
    if pow==n:break
    dir+=1
    for i in range(n-1,-1,-1):
        if cm[i]==0 and pow>=cm[i]:
            pow+=1
            cm[i]=1
print(dir)
        

