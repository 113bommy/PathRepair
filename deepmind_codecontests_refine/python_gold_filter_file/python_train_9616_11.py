n=int(input())
t=list(map(int,input().split()))
a,b,c=t[0]%2!=0,t[1]%2!=0,t[2]%2!=0
if (a and b)or(a and c)or(b and c):
    for i in range(n):
        if t[i]%2==0:
            print(i+1)
            break
else:
    for i in range(n):
        if t[i]%2!=0:
            print(i+1)
            break