c = []
n,m = map(int,input().split())
for i in range(n):
    
    for j in input().split():
        c.append(j)

if any(_ in ['C','M','Y','G'] for _ in c) :
    print("#Color")
else :
    print("#Black&White")