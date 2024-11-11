import sys 
class SegmentTree:
    def __init__(self, data, default=999999999999999999999999999999999, func=lambda a,b:min(a,b)):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()
 
        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])
 
    def __delitem__(self, idx):
        self[idx] = self._default
 
    def __getitem__(self, idx):
        return self.data[idx + self._size]
 
    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1
 
    def __len__(self):
        return self._len
 
    def query(self, start, stop):
        if start == stop:
            return self.__getitem__(start)
        stop += 1
        start += self._size
        stop += self._size
 
        res = self._default
        while start < stop:
            if start & 1:
                res = self._func(res, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res = self._func(res, self.data[stop])
            start >>= 1
            stop >>= 1
        return res
 
    def __repr__(self):
        return "SegmentTree({0})".format(self.data)
n,q=map(int,input().split())
l=list(map(int,input().split()))
re=0 
ma=max(l)
if ma>q:
    print("NO")
    sys.exit()
elif ma<q:
    re=1
for i in range(n-1):
    if l[i]==0:
        l[i]=l[i+1]
        if re==1:
            l[i]=q
            re=0
for i in range(n):
    if l[i]==0:
        #print(i)
        l[i]=l[i-1]
        if re==1:
            l[i]=q
            re=0
if l[0]==0:
    l[0]=l[1]
if sum(l)==0:
    re=0
    l=[q]*n
ind=dict()
if re==1:
    print("NO")
    sys.exit()
s=set()
f=0
sw=SegmentTree(l)
for i in range(n):
    if l[i] not in s:
        ind.update({l[i]:i})
        s.add(l[i])
    else:
        mi=sw.query(ind[l[i]],i)
        if mi<l[i]:
            f=1
            break 
        else:
            ind[l[i]]=i  
if f==1:
    print("NO")
else:
    print("YES")
    print(*l,sep=" ")
        
    
