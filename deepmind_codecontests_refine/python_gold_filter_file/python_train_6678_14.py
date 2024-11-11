
n = int(input())
l = list(map(int,input().split()))

hash = {}
max = 0
ans = 0
for i in l:

    try:
        hash[i]
    except:
        hash[i] = 1

    else:
        hash[i]+=1

    if hash[i]>max:
        max = hash[i]
        ans = i
posn = []
for i in range(n):
    if l[i] == ans:
        posn.append(i)

z = posn[0]

print(n-len(posn))
for i in range(z,n-1):
        if l[i+1]!=ans:
            if l[i+1]>ans:
                print(2,i+2,i+1)
            else:
                print(1,i+2,i+1)
        l[i+1] = ans

for i in range(z,0,-1):
        if l[i-1]!=ans:
            if l[i-1]>ans:
                print(2,i,i+1)
            else:
                print(1,i,i+1)
        l[i-1] = ans


