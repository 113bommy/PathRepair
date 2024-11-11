# n=int(input())
# li=[int(i) for i in input().split()]
# q=int(input())
N = 1e5;
n=0
t=[0]*int((2 * N))
def build():
  i = n - 1
  while( i > 0) : 
    t[i] = t[i<<1] + t[i<<1|1]
    i-=1
def modify(p, value):
    p += n
    t[p] = value;
    while ( p > 1 ):
        t[p>>1] = t[p] + t[p^1];
        p >>= 1
def query(l, r):
    res = 0;
    l += n;
    r += n;
    while(l < r):
        if (l&1):
            res += t[l]
            l+=1
        if (r&1):
            r-=1
            res += t[r]
        l >>= 1
        r >>= 1 
    return res
n=int(input())
x=[int(i) for i in input().split()]
k=0
for i in x:
    t[n+k]=i
    k+=1
build();
# modify(0, 1);
# print(query(0,3))


print(t[:50])
for i in range(int(input())):
    candies=0
    x,y=input().split()
    x,y=int(x)-1,int(y)-1
    # v=li[x:y]
    h=0
    v2=[]
    l=query(x,y+1)
    # print(l)
    # print(l)
    v=l-l%10
    candies=v//10

        # if (len(v))%2!=0:    v2.append(v[-1])
        # v=v2[:]
        # h+=1
        # if h==10:
        #     break
    print(candies)
    
    


