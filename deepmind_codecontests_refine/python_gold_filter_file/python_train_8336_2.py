from collections import*
input()
a=Counter(map(int,input().split()))
p=[1<<i for i in range(31)]
print(sum(a[x]for x in a if not any(y-x in a and(y!=x*2or a[x]>1)for y in p)))