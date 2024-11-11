x=int(input())
cnt=0
a=[]
for i in range(1,11):
    for j in range(1,32):
        a.append(j**i)
a=[l for l in a if l <= x]
print(max(a))