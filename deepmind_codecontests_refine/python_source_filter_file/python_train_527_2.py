n = input().split()
k = int(n[1])
n = int(n[0])
s = input()
l = []
w = []
for i in range(27):
    w.append(False)
for i in s:
    w[ord(i)-96] = True
    #l.append(ord(i)-96)
for i in range(27):
    if (w[i]):
        l.append(i)
l.sort()
#print(l)
i = 1
a = 0
m = l[0]
last = m
f = True
while i < k:
    #print("a: "+str(a)+ "i: " +str(i))
    
    if(a+2 < len(l)):
        if (l[a+1]-l[a])>1:
            i += 1
            a += 1
            last = l[a]
            m += last
        else:
            if (a+3<len(l)):
                i += 1
                a += 2
                last = l[a]
                m += last
            else:
                print("-1")
                f=False
                break
    else:
        print("-1")
        f=False
        break
if (f):
    print(m*f)
    
