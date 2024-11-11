s=input()
s1=s.split()
tot=int(s1[0])

s=input()
s1=s.split()

time=int(s1[0])
mon=int(s1[1])

s=input()
s1=s.split()

p1=[int(i) for i in s1]

s=input()
s1=s.split()

p1cost=[int(i) for i in s1]

s=input()
s1=s.split()

p2=[int(i) for i in s1]


s=input()
s1=s.split()

p2cost=[int(i) for i in s1]

def fun(cost):
    
    global p2
    global p2cost
    l=0
    r=len(p2)-1

    while l<r:

        mid=(l+r+1)//2

        if p2cost[mid]>cost:

            r=mid-1
        else:

            l=mid

    mid=(l+r+1)//2



    if p2cost[mid]>cost:

        return(0)
    else:
        return(p2[mid])

minval=tot*time
for i in range(len(p1)):

    if p1cost[i]<=mon:

        minval=min(minval,(tot-fun(mon-p1cost[i]))*(p1[i]))

minval=min(minval,(tot-fun(mon))*time)
print(minval)

    
