n= int(input())
#arr = [int(i) for i in input().split()]
arr = []

count = 0
found = False
for i in input().split():
    arr.append(int(i))
    if i=='5':
        count+=1

if n==count:
    print(-1)
elif  count<9:
    print(0)
else:
    print('5'*(count - count%9)+'0'*(n-count))