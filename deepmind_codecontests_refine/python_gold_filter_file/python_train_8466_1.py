def binary_search(arr, x):
    arr.sort()
    low = 0
    high = len(arr) - 1
    mid = 0
    while low <= high:

        mid = low + (high-low)//2
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid
    return -1
def ternary_search(l, r, key, ar):
    if (r >= l):
        mid1 = l + (r - l) // 3
        mid2 = r - (r - l) // 3
        if (ar[mid1] == key):
            return mid1
        if (ar[mid2] == key):
            return mid2
        if (key < ar[mid1]):
            return ternary_search(l, mid1 - 1, key, ar)
        elif (key > ar[mid2]):
            return ternary_search(mid2 + 1, r, key, ar)
        else:
            return ternary_search(mid1 + 1,
                                 mid2 - 1, key, ar)
    return -1
def cheaker(x):
    cnt= 0
    for i in range(n):
        cnt+= ((a[i]*x)//b[i] +1)
    return cnt

def binary_search_answer(low,high):

    while((high - low )> 0):
        mid = (high+low)//2
        if cheaker(mid)<c:
            low= mid+1
        else:
            high = mid

    if cheaker(low)==c :
        return low
    else:
        return -1
def binary_search_answer2(low,high):

    while((high - low )> 0):
        mid = (high+low+1)//2
        if cheaker(mid)<=c:
            low= mid
        else:
            high = mid-1

    if cheaker(low )==c:
        return low
    else:
        return -1

if __name__ == "__main__":



    n,c= map(int,input().split())
    a=[0 for i in range(n)]
    b= [0 for i in range(n)]
    flag=True
    for j in range(n):
        a[j],b[j]= map(int,input().split())
        if a[j]!=0:
            flag=False
    z = 10**9
    if flag and n==c :
        print(0)
    elif  n== c:
        print((min(b)-1)//a[0])
    elif flag :
        print(-1)

    elif n<c:
        an1=binary_search_answer(1,10**18)
        an2= binary_search_answer2(1,10**18)
        if  an1 ==-1 or an2 == -1:
            print(0)
        else:
            print(an2-an1 +1)
    else:
        print(0)