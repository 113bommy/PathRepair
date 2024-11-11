from sys import stdin,stdout
T=int(stdin.readline().strip())
for caso in range(T):
    n,k=map(int,stdin.readline().strip().split())
    #s=list(set(list(map(int,stdin.readline().strip().split()))))
    s=list(stdin.readline().strip())
    
    s.sort()
    s1=""
    for i in s:
        s1+=i
    s=s1
    if k==1:
        print(s1)
        continue
    if  s[0]!=s[k-1] or k==len(s):
        print(s[k-1])
        continue

    if s[k]==s[-1]:
        x=(len(s)-k)
        y=x//k
        if x%k!=0:
            y=+1
        print(s[k-1]+s[k]*y)
        continue
    print(s1[k-1::])

        
#n,m=map(int,stdin.readline().strip().split())
#s=list(map(int,stdin.readline().strip().split()))
