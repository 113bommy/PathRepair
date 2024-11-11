s=input()
k=int(input())
i=0
for c in s:
    if c!="1":break
    i+=1
if k < i:print("1")
else:print(c)