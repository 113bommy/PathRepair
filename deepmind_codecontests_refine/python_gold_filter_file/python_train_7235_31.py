n=int(input())
lst = list(map(int, input().strip().split(' ')))
c=abs(lst[0])
for j in range(1,n):
    c+=abs(lst[j]-lst[j-1])
print(c)