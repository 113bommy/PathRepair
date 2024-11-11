n, h = input().split()
lis = list((map(int, input().split())))[:int(n)]
sum = 0
for i in lis:
    if int(h) >i:
        sum+=2
    else:
        sum+=1

print(sum)