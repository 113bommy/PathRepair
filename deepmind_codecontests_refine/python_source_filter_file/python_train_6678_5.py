from collections import Counter
n = int(input())
l = list(map(int,input().split()))

d = Counter(l)

mxc = 0
mx = 0
for i in d:
    if d[i] >= mxc:
        mx = i
        mxc = d[i]

idx = []
for i in range(n):
    if l[i] == mx:
        idx.append(i)
'''
s = []
for i in l:
    s.append(str(i))

s = ''.join(s)
k = s.split(str(mx))

i = 0
while k[i] == '':
    i += 1


for i in k:
'''
ans = []
c = 0


for i in range(idx[0]-1,-1,-1):
    #print("smth",i)
    if l[i] == mx:
        continue
    elif l[i] > mx:
        ans.append((2,i+1,i+2))
    else:
        ans.append((1,i+1,i+2))


for i in range(1,len(idx)):
    for j in range(idx[i],idx[i-1],-1):
        if l[j] == mx:
            continue
        elif l[j] > mx:
            ans.append((2,j+1,j+2))
        else:
            ans.append((1,j+1,j+2))

for j in range(idx[-1]+1,n):
    if l[j] == mx:
        continue
    elif l[j] > mx:
        ans.append( (2,j+1,j) )
    else:
        ans.append( (1,j,j+1) )

print(len(ans))
for i in ans:
    print(*i)

'''
before = 0
ans = []
for i in range(len(idx)):
    if i == 0:
        for j in range(idx[i],-1,-1):
            if l[j] == mx:
                continue
            elif l[j] > mx:
                #print("cse 1")
                ans.append( (2,j+1,j+2) )
            else:
                #print("cse 2")
                ans.append( (1,j+1,j+2) )

            before = idx[i]
    else:
        #print(idx[i],before)
        for j in range(idx[i],before,-1):
            if l[j] == mx:
                continue
            elif l[j] > mx:
                #print("yeha")
                ans.append( (2,j+1,j+2) )
            else:
                #print("ya fir")
                ans.append( (1,j+1,j+2) )

            before = idx[i]

for j in range(idx[-1]+1,n):
    if l[j] == mx:
        continue
    elif l[j] > mx:
        #print("cs 4")
        ans.append( (2,j+1,j) )
    else:
        #print("cs 5")
        ans.append( (1,j,j+1) )

print(len(ans))
for i in ans:
    print(*i)
'''
