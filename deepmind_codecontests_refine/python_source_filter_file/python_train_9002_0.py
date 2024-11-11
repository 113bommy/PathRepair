def proA(arr):
    ans=0
    for i in arr:
        x,y,a,b=i
        ans+= (a-x)*(b-y)
    return ans
arr=[]
t=int(input())
for i in range(t):
    #n=int(input())
    arr.append(list(map(int,input().split())))
    #proD(arr)
print(proA(arr))