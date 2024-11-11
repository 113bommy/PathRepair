def binarySearch (arr, l, r, x): 
  
    # Check base case 
    if r >= l: 
  
        mid = l + (r - l)//2
  
        # If element is present at the middle itself 
        if arr[mid] == x: 
            return mid 
          
        # If element is smaller than mid, then it  
        # can only be present in left subarray 
        elif arr[mid] > x: 
            return binarySearch(arr, l, mid-1, x) 
  
        # Else the element can only be present  
        # in right subarray 
        else: 
            return binarySearch(arr, mid + 1, r, x) 
  
    else: 
        # Element is not present in the array 
        return -1
n,k=map(int,input().split())
l=list(map(int,input().split()))
ans=[]
s=list(set(l))
s.sort()
sl=len(s)
cou=[]
for j in range(sl):
    cou.append(0)
m=0
h=0
for j in range(n):
    a=binarySearch(s,0,sl-1,l[j])
    if cou[a]==0:
        if m==k+h:
            b=binarySearch(s,0,sl-1,ans[h])
            cou[b]-=1
            h+=1
            ans.append(l[j])
            cou[a]+=1
            m+=1
        else:
            ans.append(l[j])
            cou[a]+=1
            m+=1
print(m-h)
for j in range(m-h-1,-1,-1):
    print(ans[j],end=' ')