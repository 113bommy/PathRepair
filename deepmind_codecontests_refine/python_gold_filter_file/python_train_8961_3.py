n=int(input())
num=tuple(map(int,input().split()))
s=''
for i in range(n):
    spis = [i]
    t=-1
    while True:
        t+=1
        if num[spis[t]]-1 not in spis:
            spis.append(num[spis[t]]-1)
        else:
            s+=str(num[spis[t]])+" "
            break
print(s)