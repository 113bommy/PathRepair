n=input()
lst=[]
w=''
for i in n:
    lst.append(i)
for j in lst:
    if(j=='0'):
        lst.remove(j)
        break
if(len(lst)==len(n)):
    print(n[::-2])
else:
    for k in lst:
        w=w+k
    print(w)
        
