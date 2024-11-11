c=0
l='02468'
d='aiuoe'
s=input()
for i in s:
    if(i in l or i in s):
        c=c+1
print(c)