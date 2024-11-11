# import sys
# sys.stdin=open('input.txt','r')
# sys.stdout=open('output.txt','w')


def arrIn():
    return list(map(int,input().split()))
def mapIn():
    return map(int,input().split())
def check_palindrome(s):
    n=len(s)
    for i in range(n):
        if s[i]!=s[n-i-1]:return False
    return True

for ii in range(int(input())):
    n,p=mapIn()
    x=n//2
    # if n==1:
    #     print(a[i])
    #     continue
    x=n//2
    if n%2==0:x-=1
    # print(x)
    if p>x:print(-1)
    else:
        a=[0]*n
        c=0
        x=n
        if c!=0:
            for i in range(1,n,2):
                a[i]=x
                x-=1
                c+=1
                if c==p:
                    break
        y=1
        for i in range(n):
            if a[i]==0:
                a[i]=y
                y+=1
        for i in range(n):
            print(a[i],end=" ")
        print()

