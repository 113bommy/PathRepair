t= input()
t = int(t)
for i in range(t):
       n,k = map(int,input().split())
       arr =[]
       arr.append(0)
       arr2 = [int(x) for x in input().split()]
       co=0;
       for j in range(1,n-1):
              arr.append(co)
              if arr2[j]>arr2[j-1] and arr2[j]> arr2[j+1]:
                    co+=1
       arr.append(co)
       ma =0
       l = -1
       for j in range(0,n-k+1):
              pe = arr[j+k-1]-arr[j+1]
              if pe>ma:
                  ma=pe
                  l=j
       print(ma+1,l+1)
              
            