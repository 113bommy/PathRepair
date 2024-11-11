from collections import Counter

s=input()[::-1]
ans=0
lst=[0]
num=0
p=1
for i in s:
    lst.append((int(i)*p+lst[-1])%2019)
    p=p*10


ans=sum(x*(x-1)//2 for x in Counter(lst).values())
print(ans)