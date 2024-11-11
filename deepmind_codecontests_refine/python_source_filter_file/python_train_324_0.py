n = int(input())
l = list(map(int,input().split()))
even = []
odd = []
for i in l:
    if(i&1):
        odd.append(i)
    else:
        even.append(i)
if(len(even)==len(odd)):
    print(0)
elif(len(even)+1==len(odd) or len(odd)+1 == len(even)):
    print(0)
else:
    if(len(even)>len(odd)):
        x = len(even)+len(odd)-1
        even.sort()
        s=0
        for i in range(x):
            s+=even[i]
        print(s)
    else:
        x = len(odd)+len(even)-1
        odd.sort()
        s=0
        for i in range(x):
            s+=odd[i]
        print(s)
