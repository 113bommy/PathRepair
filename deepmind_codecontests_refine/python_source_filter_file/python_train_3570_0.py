t=int(input())
def check_first_x(x):
    i=x-1;j=n-1
    while i>=0:
        if arr[i]>left[j]:
            return False
        i-=1;j-=1
    return True

def check_last_x(x):
    i=n-1;j=x-1
    while j>=0:
        if arr[i]<left[j]:
            return False
        i-=1;j-=1
    return True

while t>0:
    t-=1
    n=int(input())
    arr=[int(x) for x in input().split()]
    left=[]
    check=set(arr)
    for i in range(1,2*n+1):
        if i not in check:
            left.append(i)
    a1=[False for x in range(n+1)]
    a2=[False for x in range(n+1)]
    ###this approach is slow as we brute force of all x but better to do binary search
    '''for x in range(n+1):
        if check_first_x(x)==True:
            a1[x]=True
        else:
            break
    for x in range(n+1):
        if check_last_x(x)==True:
            a2[x]=True
        else:
            break'''
    ##bs approach
    start=0;end=n-1;index=None
    while start<=end:
        if start==end:
            if check_first_x(end)==True:
                index=start
        mid=(start+end)//2
        if check_first_x(mid)==True:
            index=mid
            start=mid+1
        else:
            end=mid-1
    if index!=None:
        for i in range(index+1):
            a1[i]=True

    start=0;end=n-1;index=None
    while start<=end:
        if start==end:
            if check_last_x(end)==True:
                index=start
        mid=(start+end)//2
        if check_last_x(mid)==True:
            index=mid
            start=mid+1
        else:
            end=mid-1

    if index!=None:
        for i in range(index+1):
            a2[i]=True


    count=0
    for i in range(n+1):
        if a1[i] and a2[n-i]:
            count+=1
    print(count)
