
import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())

#def get_list(): return list(map(int, sys.stdin.readline().strip().split()))


#for ad in range(int(input())):
n=int(input())
l=list(get_ints())
q=int(input())
s=[]
c=0
for i in range(n):
    c+=l[i]
    s.append(c)
for i in range(q):
    l,r=get_ints()
    if l>1:x=s[l-1]
    else:x=0
    #print(s[r-1])
    print((s[r-1]-x)//10)