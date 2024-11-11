def rank_list(k,array):
    d={}
    for i in range(len(array)):
        for j in range(len(array)-1):
            if array[j+1][0]>array[j][0]:
                array[j],array[j+1]=array[j+1],array[j]
            elif array[j+1][0]==array[j][0] and array[j+1][1]<array[j][1]:
                 array[j],array[j+1]=array[j+1],array[j]
    a=array[k]
    print(array.count(a))
    
##    for i in range(len(array)):
##        count=0
##        for j in range(i,len(array)):
##            if array[i]==array[j]:
##                count+=1
##        for m in range(1,count+1):
##            if i+m not in d.keys():
##                d[i+m]=count
##    print(d[int(k)])
        
n,k=input().split()
array=[]
for i in range(int(n)):
    array.append([int(x) for x in input().split()])
rank_list(int(k),array)
    
        
