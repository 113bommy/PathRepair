a,b,c=map(int,input().split())
d=list(map(int,input().split()))
e=[]

for i in d:
    e.append(str(i*b%c//b))

print(' '.join(e))