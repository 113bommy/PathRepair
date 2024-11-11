n=int(input())
x=list(map(int,input().split()))

s=set()

for i in x:
    if i!=0:
        s.add(i)

print(len(s))