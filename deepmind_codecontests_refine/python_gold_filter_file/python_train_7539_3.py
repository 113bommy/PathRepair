import collections
def m():
    # n= "aaabbac"
    # m= "aabbccac"
    n = input()
    m = input()
    nhash = collections.defaultdict(int)
    mhash = collections.defaultdict(int)
    for i in n:
        nhash[i] +=1
    for i in m:
        mhash[i] +=1
    sum = 0
    for i,k in mhash.items():
        if(nhash[i] ==0):
            return 0
        sum += min(k,nhash[i])
    return sum


res = m()

if  res == 0:
    print(-1)
else:
    print(res)
