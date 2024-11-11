# coding: utf-8
# Your code here!
k = int(input())
count = 0
ans = []
minN = 10**15

for i in reversed(range(12)):
    minN = 10**15
    for j in reversed(range(1,10**3)):
        num = str(j)+"9"*i
        n = sum([int(k) for k in num])
        n = int(num)/n
        if(minN > n or n==1):
            minN = n
            ans.append(int(num))

for i in list(sorted(list(set(ans))))[:k]:
    print(i)