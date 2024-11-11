import bisect

def mini_idex(d,ele,prev):
    t = bisect.bisect_right(d[ele],prev)
    if t>=len(ele):
        return -1
    else:
        return d[ele][t]

tt = int(input())

while tt!=0:

    s=input()
    t=input()
    d = {}
    for i in range(26):
        d[chr(ord("a")+i)]=[]
    for i in range(len(s)):
        d[s[i]].append(i)

    f=0
    i=0
    count=0
    prev = -1
    while i<len(t):
        if len(d[t[i]])==0:
            f=1
            break
        else:
            temp = mini_idex(d,t[i],prev)

            if temp==-1:
                count+=1
                prev=-1

            else:
                prev=temp
                i += 1


    if f==1:
        print(-1)
    else:
        count+=1
        print(count)











    tt-=1