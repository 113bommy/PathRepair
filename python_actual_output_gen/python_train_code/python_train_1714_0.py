def candy_man(n,k):
    sum=0
    curr=n
    while curr>0:
        m=min(k,curr)
        sum+=m
        curr-=m
        curr-=curr//10
    if sum*2>=n:
        return True
    else:
        return False

def k_maker(n):
    high=n
    low=1
    mid=(high+low)//2
    while low!=high:
        if candy_man(n,mid):
            high=mid
            mid=(low+high)//2
        else:
            low=mid+1
            mid=(high+low)//2
    print(low)
# n=int(input())
k_maker(1)