n=input()
s=list(map(int,input().split()))
for i in s:
    while s.count(i)-1:
        s.remove(i);
print(len(s))
for i in s:
 print(i,end=' ')