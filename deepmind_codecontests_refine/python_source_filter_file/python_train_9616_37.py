import math
c=int(input())
l=input().split()
even="0"
evencount=0
odd="0"
oddcount=1
for n in range(c):
    if int(l[n])%2==0:
        even="1"+even
        evencount+=1
        odd="0"+odd
    else:
        even="0"+even
        odd="1"+odd
        oddcount+=1
if evencount>oddcount:
    print(int(math.log10(int(odd))))
else:
    print(int(math.log10(int(even))))