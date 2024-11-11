import sys

# def recur(pre,p,pos,maxx,temp):
#     if pos == len(pre):
#         maxx[0] = max(maxx[0],temp)
#         return
    
#     for i in range(0,p+1):
#         if i < len(pre[pos]) :
#             temp = temp + pre[pos][i]
#             recur(pre,p-i,pos+1,maxx,temp)
#             temp = temp - pre[pos][i]

RI = lambda : [int(x) for x in sys.stdin.readline().split()]
ri = lambda : sys.stdin.readline().strip()

# for _ in range(int(ri())):
def query(seg,ss,se,qs,qe,pos):
    if qs <= ss and qe >= se:
        return seg[pos]
    if qs > se or qe < ss:
        return [0,0]
    mid= (ss+se)//2
    left = query(seg,ss,mid,qs,qe,2*pos+1)
    right = query(seg,mid+1,se,qs,qe,2*pos+2)
    # print(left,right)
    return [(left[0]+right[0])%10,left[1]+right[1] + (1 if (left[0]+right[0]) > 10 else 0)]

def build(seg,pos,a,s,e):
    if s == e:
        seg[pos][0] = a[s]
        seg[pos][1] = 0
        return 
    mid= (s+e)//2
    build(seg,2*pos+1,a,s,mid)
    build(seg,2*pos+2,a,mid+1,e)
    seg[pos][1] = seg[2*pos+1][1] + seg[2*pos+2][1]
    num1 = seg[2*pos+1][0]
    num2 = seg[2*pos+2][0]
    if (num1+num2)>=10:
        seg[pos][1]+=1
    seg[pos][0]  = (num1+num2)%10

n = int(ri())
a = RI()
seg = [[0,0] for i in range(0,4*n+1)]

build(seg,0,a,0,n-1)
# print(seg)
q = int(ri())
for _ in range(q):
    l,r  = RI()
    l-=1
    r-=1
    res = query(seg,0,n-1,l,r,0)
    print(res[1])