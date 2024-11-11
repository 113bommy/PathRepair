i=1
summer=1
a=[]
while(i<2*10**9):
    a.append(i)
    i=i+summer
    summer=summer+1
def binarySearch(a,x): 
    l=0
    r=len(a)-1
    if(a[r]>=x):
        return r,x-a[r]
    while l <= r: 
  
        mid = l + (r - l)//2; 
          
        # Check if x is present at mid 
        if (a[mid] <= x and a[mid+1]>x): 
            return mid,x-a[mid] 
  
        # If x is greater, ignore left half 
        elif a[mid] < x: 
            l = mid + 1
  
        # If x is smaller, ignore right half 
        else: 
            r = mid - 1
    
for _ in range(int(input())):
    n,k= map(int,input().split())
    x1,x2 = binarySearch(a,k)
    # print(x1,x2)
    x1 = n-2-x1
    x2=  n-1-x2
    li=[]
    for i in range(n):
        if(i==x1 or i==x2):
            li.append('b')
        else:
            li.append('a')
    String=''.join(li)
    print(String)
    

    
    
    
    
