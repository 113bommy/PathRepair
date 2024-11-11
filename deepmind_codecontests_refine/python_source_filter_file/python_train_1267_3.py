from sys import stdin, stdout
 
 
def main():
    arr1 = [int(x) for x in stdin.readline().split()]
    arr2 = [int(x) for x in stdin.readline().split()]
    n= arr1[0]
    x=arr1[1]
    y=arr1[2]
    ans = 0
    length = len(arr2)
    for i in range(length):
        if lessx(x,arr2,i) and lessy(y, arr2,i):
            print (i)
            return
    
        
    
def lessx(x, arr, i):
    bool = 1
    for b in range(x):
        if i-b >0:
            if arr[i-b]<arr[i]:
                bool = 0
    if bool == 1:
        return True
    else :
        return False
    return False
    
def lessy(y, arr, i):
    bool = 1
    for b in range(y):
        if i+b <len(arr):
            if arr[i+b]<arr[i]:
                bool = 0
    if bool == 1:
        return True
    else :
        return False
    return False
    
if __name__ =="__main__":
    main()