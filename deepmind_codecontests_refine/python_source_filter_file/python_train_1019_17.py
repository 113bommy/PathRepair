input()
s=input()
cnt=s.count(".")
l=[]
for i in s:
    cnt= cnt-1 if i=="." else cnt+1
    l.append(cnt)
print(min(l))    