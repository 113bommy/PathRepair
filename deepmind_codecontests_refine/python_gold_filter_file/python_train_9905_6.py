def func(clown,acro,x):
    if clown[x]=="1":
        if acro[x]=="1":
            return 3
        else:
            return 1
    else:
        if acro[x]=="1":
            return 2
        else:
            return 0
def main():
    length=int(input())
    clown=input()
    acro=input()
    arr=[0,0,0,0]
    for x in range(length):
        arr[func(clown,acro,x)]+=1
    bound=arr[2]+arr[3]-length//2
    bo=False
    for a in range(arr[0]+1):
        d=a+bound
        if d>=0 and d<=arr[3]:
            for b in range(arr[1]+1):
                c=length//2-a-b-d
                if c>=0 and c<=arr[2]:
                    bo=True
                    break
        if bo:break
    #print(arr)
    if bo:
        arr[0]=a
        arr[1]=b
        arr[2]=c
        arr[3]=d
        #print(a,b,c,d)
        for x in range(length):
            test=func(clown,acro,x)
            if arr[test]>0:
                arr[test]-=1
                print(x+1,end=" ")
    else:
        print(-1)
main()
