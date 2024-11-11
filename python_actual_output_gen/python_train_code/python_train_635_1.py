st=input()
ls=[]
i=0
while i<len(st):
    j=i
    count=1
    while j<(len(st)-1) and st[j]==st[i] and st[j+1]==st[i]:
        count+=1
        j+=1
    if count:
        ls.append((count,st[i])) 
    i+=count
if len(ls)%2==0:
    print(0)
else:
    mid=(len(ls)//2)
    if ls[mid][0]==1:
        print(0)
    else:
        i=mid
        while i:
            left,right=mid-i,mid+i
            i-=1
            if ls[left][1]==ls[right][1] and ls[left][0]+ls[right][0]<3:
                print(0)
                break             
        else:
            print(ls[mid][0]+1)