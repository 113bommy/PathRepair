a, b = map(int, input().split())
l = list(map(str, input().split()))
c = 0
for i in l:
    if(i.count('4') and i.count('7'))<=b:
        c+=1
    else:
        continue
print(c)
