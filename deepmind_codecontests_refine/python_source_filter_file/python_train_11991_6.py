def bin_s(x,values,arr):
    i=0
    j=len(arr)-1
    while(i<j):
        m=(i+j)//2
        if(arr[m]<=values):
            i=m+1
        else:
            j=m
    if(arr[i]>=values):
        return arr[i-1]
    return arr[i]

def bin_s1(x,values,arr):
    i=0
    j=len(arr)-1
    while(i<j):
        m=(i+j)//2
        if(arr[m]<values):
            i=m+1
        else:
            j=m
    if(arr[j]<=values):
        return arr[j+1]
    return arr[j]



st_a=input()
st_b=input()
table=[[] for i in range(26)]
count=0
for i in st_a:
    table[ord(i)-97].append(count)
    count+=1
record_l=[0]*(len(st_b))
record_f=[0]*(len(st_b))
record_l[-1]=table[ord(st_b[-1])-97][-1]
record_f[0]=table[ord(st_b[0])-97][0]
for i in range(len(st_b)-2,-1,-1):
    record_l[i]=bin_s(ord(st_b[i])-97,record_l[i+1],table[ord(st_b[i])-97])
for i in range(1,len(st_b)):
    record_f[i]=bin_s1(ord(st_b[i])-97,record_f[i-1],table[ord(st_b[i])-97])

maxi=0
record_f=[-1]+record_f
record_l.append(len(st_a))
for i in range(len(st_b)+1):
    maxi=max(record_l[i]-record_f[i]-1,maxi)
print(maxi)