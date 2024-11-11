def subseq(t,s):
    if len(t)==0:
        return True
    for i in range(len(s)):
        if s[i]==t[0]:
            return subseq(t[1:],s[i+1:])
    return False        

s=str(input())
t=str(input())
s1=[]
t1=[]
for j in s:
    s1.append(str(j))
for j in t:
    t1.append(str(j))
flag=True
for i in t1:
    if not i in s1:
        print("need tree")
        flag=False
        break
    else:
        s1.remove(i)
if flag:
    if len(s)==len(t):
        print("array")
    elif subseq(t,s):
        print("automaton")
    else:
        print("both")