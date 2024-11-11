q = int(input())
l=[]
from math import log
 
def converter(number, base):
    figures = [int(i,base) for i in str(number)]
    figures = figures[::-1]
    result = 0
    for i in range(len(figures)):
        result += figures[i]*base**i
    return result
 
for i in range(q):
    n = int(input())
    def basecvt(x,b=3):
        e = x//b
        q = x%b
        if n == 0:
            return '0'
        elif e == 0:
            return str(q)
        else:
            return basecvt(e) + str(q)
    st = basecvt(n)
    ans=0
    if st.replace("1","").replace("0","") == "":
        ans=st
    else:
        if st.replace("2","") == "":
            ans="1"+"0"*len(st)
        else:
            two = st.find("2")
            p2 = "" + "0"*(len(st) - two)
            st = st[:two]
            if st.replace("1","") == "":
                p1 = "1"+"0"*len(st)
            else:
                zero = st.rfind("0")
                p1 = st[:zero] + "1" + st[(zero+1):]
            ans = p1+p2
        
    l.append(converter(int(ans),3))
 
print("\n".join(str(k) for k in l))