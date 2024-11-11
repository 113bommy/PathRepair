# limit for array size  
N = 200001;  
  
# Max size of tree  
tree = [0] * (2 * N);  
  
# function to build the tree  
def build(arr) : 
  
    # insert leaf nodes in tree  
    for i in range(n) :  
        tree[n + i] = arr[i];  
      
    # build the tree by calculating parents  
    for i in range(n - 1, 0, -1) :  
        tree[i] = tree[i << 1] + tree[i << 1 | 1];  
  
# function to update a tree node  
def updateTreeNode(p, value) :  
      
    # set value at position p  
    tree[p + n] = value;  
    p = p + n;  
      
    # move upward and update parents  
    i = p; 
      
    while i > 1 : 
          
        tree[i >> 1] = tree[i] + tree[i ^ 1];  
        i >>= 1;  
  
# function to get sum on interval [l, r)  
def query(l, r) :  
  
    res = 0;  
      
    # loop to find the sum in the range  
    l += n; 
    r += n; 
      
    while l < r : 
      
        if (l & 1) : 
            res += tree[l];  
            l += 1
      
        if (r & 1) : 
            r -= 1; 
            res += tree[r];  
              
        l >>= 1; 
        r >>= 1
      
    return res;  
from collections import defaultdict
import bisect
#a,b = map(int,input().strip().split())
n = int(input().strip())
a = [int(i) for i in input().strip().split()]
b = [int(i) for i in input().strip().split()]
minus = [(a[i] - b[i],i) for i in range(n)]
minus.sort()
#print(minus)
order = dict()
for index,i in enumerate(minus):
    order[i[1]] = index
minus = [i[0] for i in minus]
total = 0
temp = [0 for i in range(n)]
build(temp)
#print(minus)
for i in range(n - 1):
    result = -(a[i] - b[i])
    ans = bisect.bisect_right(minus,result)
    
    total += n - ans
    #print('i',i,'total',total)
    if ans < n:
        total -= (1 if result < a[i] - b[i] else 0)
        total -= query(ans,n)
        #print('query from ', ans," to ",n," is: ",query(ans,n))
    #print('i:{},result:{},ans:{},total:{}'.format(i,result,ans,total))
    updateTreeNode(order[i], 1)
    print(order[i])
print(total)
