t=int(input())
l=[]
for i in range(t):
    a,b=map(int,input().split(' '))
    l.append((b-(a%b))%b)
for i in l:
    print(i)