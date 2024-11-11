n=int(input())
a=list(map(int, input().split()))

r=[0]*n

for i in range(n)[::-1]:
    if sum(r[i::i+1]) != a[i]:
        r[i]=1

print(sum(r))
for index, i in enumerate(r):
    if i == 1:
        print(index+1)

