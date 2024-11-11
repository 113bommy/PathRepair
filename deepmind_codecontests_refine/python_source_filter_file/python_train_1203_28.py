grass = input()
last = -1
mn=0
for i in range(0,len(grass) -1):
    #print(i)
    if (['A','E','I','O','U']).count(grass[i])>0:
       # print(i)
        if mn<i-last:
            mn=i-last
        last=i

if mn<len(grass)-last:
    mn = len(grass) - last

print(mn)