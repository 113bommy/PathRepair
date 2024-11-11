r=0
for i in range(int(input())):
    p,q=map(int, input().split())
    if p<q:
        r+=1
print(r)