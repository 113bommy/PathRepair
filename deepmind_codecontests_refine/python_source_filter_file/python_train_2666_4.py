input()
l=list(input().split())
for i in l:
    a=0
    for j in i:
        if ord(j)<91:
            a+=1;
    m=max(a,0)
print(m)
