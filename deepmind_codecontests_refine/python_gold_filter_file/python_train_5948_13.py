inp=int(input())
x=list(input())

i = 0
cnt = 0
res =[]
while i < inp:
    cnt +=1
    res.append(x[i])
    i+=cnt

print(''.join(res))