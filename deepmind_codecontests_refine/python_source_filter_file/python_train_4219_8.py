n = int(input())
m = int(input())
l=[]
for i in range(n):
    l.append(int(input()))

l.sort(reverse=True)
c = 0


if m in l:
    print (1)
else:
    for i in range(len(l)):
        if m>l[i]:
            m-=l[i]
            #print (m)
        elif m<=l[i]:
            c=i
            break
print(c+1)