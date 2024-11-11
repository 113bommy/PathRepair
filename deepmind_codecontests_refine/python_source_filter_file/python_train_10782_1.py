a,b,c =list(map(int,input().split()))
n = int(input())
usb = list()
pc2 = list()
for i in range(n):
    kl = input().split()
    if(kl[1]=="USB"):
        usb.append(int(kl[0]))
    else:
        pc2.append(int(kl[0]))
usb = sorted(usb)
pc2 = sorted(pc2)
summ = 0
num = 0
i = 0
j = 0
can = True
if(len(usb)<=a):
    summ+=sum(usb)
    i=len(usb)
    a-=len(usb)
    num+=i
else:
    summ+=sum(usb[0:a])
    i=a
    a=0
    num+=i

if(len(pc2)<=b):
    summ+=sum(pc2)
    j=len(pc2)
    b=0
    num+=len(pc2)
else:
    summ+=sum(pc2[0:b])
    j=b
    b=0
    num+=j
#print(j, summ, num)
while (c>0 and( i<len(usb) or j <len(pc2))):
    if(i>=len(usb)):
        if(len(pc2)-j>=c):
            summ+=sum(pc2[j:j+c])

            num+=c
            c=0
        else:
            summ+=sum(pc2[j:])
            c=0
            num+=len(pc2[j:])
    elif(j>=len(pc2)):
        if(len(usb)-i>=c):
            summ+=sum(usb[i:i+c])

            num+=c
            c=0
        else:
            summ+=sum(usb[i:])

            num+=len(usb[j:])
            c=0
    else:
        num+=1
        if(usb[i]<=pc2[j]):
            summ+=usb[i]
            c=c-1
            i+=1
        else:
            summ+=pc2[j]
            c=c-1
            j+=1
print(num, summ)
