a,b = input().split()
l = len(a)
li = [a[0],b[0]]
j = 1
for i in range(1,l):
    if li[-1]<a[i]:
        li.insert(j,a[i])
    else:
        break
    j+=1
print("".join(li))


