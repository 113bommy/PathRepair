n=0
for i in range(int(input())):
    p,q=map(int,input().split())
    if p-q>=2:
        n+=1
print(n)