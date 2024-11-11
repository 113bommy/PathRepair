"""
arr = list(map(int, input().split()))
n,k=map(int, input().split())
"""
def binarySearch (arr, l, r, x): 
  
    # Check base case 
    if r >= l: 
  
        mid = l + (r - l)//2
  
        # If element is present at the middle itself 
        if arr[mid][0] <=x and arr[mid][1] >= x: 
            return mid 
          
        # If element is smaller than mid, then it can only 
        # be present in left subarray 
        elif arr[mid][0] > x: 
            return binarySearch(arr, l, mid-1, x) 
  
        # Else the element can only be present in right subarray 
        else: 
            return binarySearch(arr, mid+1, r, x) 
  
    else: 
        # Element is not present in the array 
        return -1
piles = int(input())
piles_arr = list(map(int, input().split()))
guesses = int(input())
guess_arr = list(map(int, input().split()))

sum_arr = [(0 , piles_arr[0])]
counter = piles_arr[0]
for i in range(1, piles):
    curr = counter
    counter += piles_arr[i]
    sum_arr.append((curr, counter))
for element in guess_arr:
    print(binarySearch(sum_arr, 0, len(sum_arr), element) + 1)
