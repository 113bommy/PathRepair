from __future__ import print_function
q=int(input())
while q > 0:
    q-=1
    lst=input()
    #taking intgers as input
    #a,b,n,s
    #print("yes")
    arr=list(map(int,lst.split()))
    s=arr[3]
    if arr[0]*arr[2] > s:
        if s%arr[0] <= arr[1]:
            print("YES")
        else:
             print("NO")
    else :
        if arr[0]*arr[2]+arr[1] < s:
            print("NO")
        else:
             print("YES")

    
