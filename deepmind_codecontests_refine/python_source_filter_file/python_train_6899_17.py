from collections import Counter
from collections import OrderedDict
from collections import defaultdict 
def freq_count(mylist):
    return Counter(mylist)
# t=int(input())
# for _ in range(t):
    #n=int(input())
    #arr=[int(x) for x in input().split()]
    #a,b=map(int,input().split())
    #print(a^b)
st=list(input())
cp=st.copy()
cp.reverse()
if st == cp:
    print(0)
else:
    print(3)
    print("R",2)
    print("L",len(st))
    print("L",2)
    