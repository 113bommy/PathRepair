n=int(input())
a=list(map(int,input().rstrip().split()))
even=[]
odd=[]
if len(a)==1:
    print(0)
    exit()
else:
    pass
for i in range(n):
    if a[i]%2==0:
        even.append(a[i])
    else:
        odd.append(a[i])
even.sort()
odd.sort()
#print(len(even),len(odd))

if  len(even)==0 and len(odd)>=1:
    odd.pop()
    print(sum(odd))
elif len(odd)==0 and len(even)>=1:
    even.pop()
    print(sum(even))
elif len(even)==len(odd):
    print(0)
elif sum(a)==0:
    print(0)
elif abs(len(odd)-len(even))==1:
    print(0)
else:
    if len(even)>len(odd):
        print(sum(even[0:len(even)-len(odd)-1]))
    else:
        print(sum(odd[0:len(odd)-len(odd)-1]))
    