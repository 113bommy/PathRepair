import string
n=int(input())
s=input()
ls=[]
alps=[]
for a in s:
    ls.append(a)
for a in string.ascii_lowercase:
    alps.append(a)
alps.reverse()
ctr=0

for i in range(25):
    j=0
    while j < (len(ls)) and len(ls)>1:
        #print(j)
        if alps[i]==ls[j]:
            for oo in range(1):
                if j!=0 and j!=len(ls)-1:
                    if (alps[i+1]==ls[j+1] or 
                             alps[i+1]==ls[j-1]):
                        #print(j)
                        ls.pop(j)
                        ctr+=1
                        j-=1
                        break
                        
                if j==0:
                    if alps[i+1]==ls[j+1]:
                        ls.pop(j)
                        ctr+=1
                        j-=1
                        break
                if j==len(ls)-1:
                    if alps[i+1]==ls[j-1]:
                        ls.pop(j)
                        ctr+=1
                        j-=1
                        break
        j+=1
print(ctr)

'''
babaababbaabbabababbabbbababababbaabababaaababaababbbaaababbaabbababababbababbabaabbaabaaaaabbababba

'''