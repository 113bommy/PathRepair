# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.
def swap(index_1,index_2,arr):
    temp=arr[index_1];
    arr[index_1]=arr[index_2]
    arr[index_2]=temp
    


def programcal(y,z):
    arr=[]
    m=z
    for i in range(y):
        t=m%10
        arr.append(t)
        m=m//10
    arr.reverse() 
    #print(arr)
    j,count=(0,0)
    while(j<y):
        if(arr[y-1]==0):
            if(arr[j]==0):
                j=j+1
            else:
                swap(y-1,j,arr)
                count=count+1
                j=j+1
        else:
            if(arr[j]==0):
                if(j==y-1):
                    break
                else:
                    j=j+1
            else:
                temp=arr[y-1];
                arr[y-1]=0
                if(j==y-1):
                    count=count+temp
                    j=j+1
                else:
                    swap(j,y-1,arr)
                    count=count+temp+1
                    j+=1
    print(count)
x=int(input())
l=0
arr1=[]
arr2=[]
while(l<x):
    y=int(input())
    arr1.append(y)
    z=int(input())
    arr2.append(z)
    l=l+1
for i in range(x):
    programcal(arr1[i],arr2[i])
