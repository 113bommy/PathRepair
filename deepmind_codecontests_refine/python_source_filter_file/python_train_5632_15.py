h=input()
x = h.split()
n=int(x[0])
m=int(x[1])
i=0
z=input()
z2=z.split()
list=[]
while i<m:
    list.append(int(z2[i]))
    i=i+1
import time 
start=time.time()

s={}                                #making a dictionary to store the no.of packets of each type
for ele in list:
    if ele not in s:
        s[ele]=1
    else:
        s[ele]=s[ele]+1
val=[]
for ele in s:
    val.append(s[ele])            #val is a list of the values in the dictionary in descending order
val.sort(reverse=True)
def maxim(list2):                 # function to find the max no.of packets of each type per person after dividing 
    lenth=len(list2)
    i=0
    maximum=list2[0].count/list2[0].ppl
    pos=0
    while i<lenth:
        if maximum<list2[i].count/list2[i].ppl:
            maximum=list2[i].count/list2[i].ppl
            pos=i
        i=i+1
    return(pos)
def minimu(list2):                # function to find the min no.of packets of each type per person after dividing
    lenth=len(list2)
    i=0
    minim=list2[0].count/list2[i].ppl
    pos=0
    while i<lenth:
        if minim>list2[i].count/list2[i].ppl:
            minim=list2[i].count/list2[i].ppl
            pos=i
        i=i+1
    return(pos)
def minimu2(list2):              # function to find the min no.of packets of each type 
    lenth=len(list2)
    i=0
    minim=list2[0].count
    pos=0
    while i<lenth:
        if minim>list2[i].count:
            minim=list2[i].count
            pos=i
        i=i+1
    return(pos)
list2=[]
class num:                                  # a class to represent each type of food packet
    count=0
    ppl=0
    name=0
for ele in s:                               # making a list of objects of each food type
    j=num()
    j.name=ele
    j.count=s[ele]
    list2.append(j)
def divin2(list2):                         
    h=maxim(list2)
    l=minimu(list2)
    if list2[h].count/(list2[h].ppl+1)>list2[l].count/(list2[l].ppl):
        list2[h].ppl=list2[h].ppl+1
        list2[l].ppl=list2[l].ppl-1
        if list2[l].ppl==0:
            list2.pop(l)
        return(divin2(list2))
    else:
        return(int(list2[l].count/(list2[l].ppl)))
def dividing(list2,n,s,m,val):
    if n>m:
        return(0)
    lenth=len(list2)
    if lenth==1:
        return(list2[0].count/n)
    
    
    if n<lenth:
        pos=0
        while len(list2)!=n:
            pp=minimu2(list2)
            list2.pop(pp)
        return(dividing(list2,n,s,m,val))
        
    elif n==lenth:
        for ele in list2:
            ele.ppl=1
        h=maxim(list2)
        l=minimu(list2)
        if list2[h].count/(list2[h].ppl+1)>list2[l].count:
            list2[h].ppl=list2[h].ppl+1
            list2.pop(l)
            return(divin2(list2))
        else:
            return(list2[l].count)
    if n>lenth:
        for ele in list2:
            ele.ppl=1
        g=n-lenth
        i=0
        
        while i<g:
            h=maxim(list2)
            list2[h].ppl=list2[h].ppl+1
            i=i+1
        l=minimu(list2)
        return(int(list2[l].count/list2[l].ppl))

counts=dividing(list2,n,s,m,val)
print(counts)
end=time.time()
