def calc(a,b,c):
    return (a-b)*(a-b)+(b-c)*(b-c)+(c-a)*(c-a)
def binarySearchCount(arr, n, key): 
  
    left = 0
    right = n - 1
  
    count = 0
  
    while (left <= right):  
        mid = int((right + left) / 2) 
  
        # Check if middle element is 
        # less than or equal to key 
        if (arr[mid] <= key):  
  
            # At least (mid + 1) elements are there 
            # whose values are less than 
            # or equal to key 
            count = mid + 1
            left = mid + 1
          
        # If key is smaller, ignore right half 
        else: 
            right = mid - 1
      
    return count 
def countGreater(arr, n, k): 
    l = 0
    r = n - 1
  
    # Stores the index of the left most element 
    # from the array which is greater than k 
    leftGreater = n 
  
    # Finds number of elements greater than k 
    while (l <= r): 
        m = int(l + (r - l) / 2) 
  
        # If mid element is greater than 
        # k update leftGreater and r 
        if (arr[m] > k): 
            leftGreater = m 
            r = m - 1
  
        # If mid element is less than 
        # or equal to k update l 
        else: 
            l = m + 1
  
    # Return the count of elements  
    # greater than k 
    return (n-leftGreater) 
 
for i in range(int(input())):
    r,g,b=map(int,input().split())
    l=list(map(int,input().split()))
    l1=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    fans=99999999999999999999999999999999999999999999999999999
    l1.sort()
    l.sort()
    l2.sort()
    for i in range(r):
        f=countGreater(l1, g, l[i])
        f1=binarySearchCount(l2, b, l[i])
        if f!=0 and f1!=0:
            fans=min(fans,calc(l[i],l2[f1-1],l1[g-f]))
    for i in range(r):
        f=countGreater(l2, b, l[i])
        f1=binarySearchCount(l1, g, l[i])
        if f!=0 and f1!=0:
            fans=min(fans,calc(l[i],l1[f1-1],l2[b-f]))
    for i in range(g):
        f=countGreater(l, r, l1[i])
        f1=binarySearchCount(l2, b, l1[i])
        if f!=0 and f1!=0:
            fans=min(fans,calc(l1[i],l2[f1-1],l[r-f]))
    for i in range(g):
        f=countGreater(l2, b, l1[i])
        f1=binarySearchCount(l, r, l1[i])
        if f!=0 and f1!=0:
            fans=min(fans,calc(l1[i],l[f1-1],l2[b-f]))
    for i in range(b):
        f=countGreater(l, r, l2[i])
        f1=binarySearchCount(l1, g, l2[i])
        if f!=0 and f1!=0:
            fans=min(fans,calc(l2[i],l1[f1-1],l[r-f]))
    for i in range(b):
        f=countGreater(l1, g, l2[i])
        f1=binarySearchCount(l, r, l2[i])
        if f!=0 and f1!=0:
            fans=min(fans,calc(l2[i],l[f1-1],l1[g-f]))
    print(fans) 