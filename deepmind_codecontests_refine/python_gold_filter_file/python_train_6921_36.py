n=int(input())
sp=sorted(list(map(int, input().split())))
count=0
s=0
for i in sp:
    if i>=s:
        count+=1
        s+=i
print(count)
