arr=list("qwertyuiopasdfghjkl;zxcvbnm,./")
ch=input()
brr=input()
brr=list(brr)
str=""
if(ch=='R'):
    for i in brr:
        x=arr.index(i)
        str=str+arr[x-1]
else:
    for i in brr:
        x=arr.index(i)
        str=str+arr[x-1]
print(str)