import sys
from math import ceil,log2; 

INT_MAX = 10**12; 


def minVal(x, y) : 
	return x if (x < y) else y; 

 
def getMid(s, e) : 
	return s + (e - s) // 2; 


def RMQUtil( st, ss, se, qs, qe, index) : 


	if (qs <= ss and qe >= se) : 
		return st[index]; 


	if (se < qs or ss > qe) : 
		return INT_MAX; 


	mid = getMid(ss, se); 
	return minVal(RMQUtil(st, ss, mid, qs, 
						qe, 2 * index + 1), 
				RMQUtil(st, mid + 1, se, 
						qs, qe, 2 * index + 2)); 


def RMQ( st, n, qs, qe) : 


	if (qs < 0 or qe > n - 1 or qs > qe) : 
	
		print("Invalid Input"); 
		return -1; 
	
	return RMQUtil(st, 0, n - 1, qs, qe, 0); 


def constructSTUtil(arr, ss, se, st, si) : 

	if (ss == se) : 

		st[si] = arr[ss]; 
		return arr[ss]; 


	mid = getMid(ss, se); 
	st[si] = minVal(constructSTUtil(arr, ss, mid, 
									st, si * 2 + 1), 
					constructSTUtil(arr, mid + 1, se, 
									st, si * 2 + 2)); 
	
	return st[si]; 


def constructST( arr, n) : 


	x = (int)(ceil(log2(n))); 


	max_size = 2 * (int)(2**x) - 1; 

	st = [0] * (max_size); 


	constructSTUtil(arr, 0, n - 1, st, 0); 


	return st; 


if __name__ == "__main__" : 
    for _ in range(int(input())):
        def solve():
        	n = int(input())
        	a =list(map(int,input().split())) 
        	st = constructST(a, n); 
        # 	print(st)
        	left=[0]*(n+1)
        	right=[0]*(n+1)
        	for i in range(1,n+1):
        	    left[i]=max(left[i-1],a[i-1])
        	    right[-i-1]=max(right[-i],a[-i])
        # 	print(left,right)    
        	for ri in range(1,n-1):
        	    ma=right[-ri-1]
        	    low=1
        	    high=n-ri-1
        	   # print(low,high)
        	    while low<high:
        	        mid=(low+high+1)//2
        	       # print(low,high,mid)
        	        if left[mid]>ma:
        	            high=mid-1
        	        else:
        	            low=mid    
        	            
        	   # print(ri,low)  
        	    if (left[low]==ma and RMQ(st, n, low, n-ri-1)==ma)  :
	                print("YES",)
	                print(low,n-low-ri,ri)
	                return
	            if (low>1 and left[low-1]==ma and RMQ(st, n, low-1, n-ri-1)==ma):
        	        print("YES",)
	                print(low-1,n-low-ri,ri)
	                return                 
        	            
        	print("NO")
        	return
        solve()    	
