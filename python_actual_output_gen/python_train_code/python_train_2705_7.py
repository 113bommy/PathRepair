n=int(input())
lis=[]
for _  in range(n):
    x,l=map(int,input().split())
    lis.append([x-l,x+l])

lis.sort(key=lambda x:x[0])
count = 0
tmp = - 10 ** 18
for i in lis:
    if tmp <= i[0]:
        count += 1
        tmp = i[1]

print(count)



