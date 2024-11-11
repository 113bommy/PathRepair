def proA(arr):
    ans=0
    for i in arr:
        x,y,a,b=i
        ans+= (a-x+1)*(b-y+1)
    return ans
arr=[]
t=int(input())
for i in range(t):
    #n=int(input())
    arr.append(list(map(int,input().split())))
    #proD(arr)
print(proA(arr))