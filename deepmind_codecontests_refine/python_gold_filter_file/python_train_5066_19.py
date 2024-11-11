import bisect
n,m =  list(map(int,input().split()))
arr = list(map(int,input().split()))
letters = list(map(int,input().split()))

prefix = [arr[0]]
for q in range(1,len(arr)):
    prefix.append(arr[q]+prefix[q-1])

# print(prefix)
l,h = 0,len(prefix)-1
for i in range(0,len(letters)):
    pre = bisect.bisect_left(prefix,letters[i])
    l = pre
    if pre==0:
        f=1
        k = letters[i]
    else:
        f = pre+1
        k = letters[i] - prefix[pre-1]
    
    print(" ".join([str(f),str(k)]))


# def bsearch(l,h,arr,x):
#     while (l<=h):
#         mid = l+ (h-l)//2
#         if arr[mid] == x:
#             return mid
#         if arr[mid] > x:
#             h = mid-1
#         else:
#             ans = l
#             l = mid+1
    
#     return ans

