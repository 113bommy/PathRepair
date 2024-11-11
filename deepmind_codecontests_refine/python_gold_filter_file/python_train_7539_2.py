def garland(a,b):
    ans=0
    for i in set(b):
        mini=min(a.count(i),b.count(i))
        if mini==0:
            return -1
        ans+=mini
    return ans

a=input()
b=input()
print(garland(a,b))