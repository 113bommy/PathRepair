inp = list(map(int,input().split()))
a=inp[0]
b=inp[1]
c=inp[2]
n=inp[3]
if(a+b<c or (a+b-c)>=n):
    print("-1")
else:
    print(n-(a+b-c))