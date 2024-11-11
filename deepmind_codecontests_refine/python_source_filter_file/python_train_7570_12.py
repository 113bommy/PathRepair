q=lambda:map(int,input().split())
qi=lambda:int(input())
qs=lambda:input().split()

def lol(n):
    for i in range(1,n+1):
        if n%i==0:
            yield i

n=qi()
a=input()
for i in lol(n):
    a=''.join(reversed(a[0:1]))+a[1:10] 
print(a)
