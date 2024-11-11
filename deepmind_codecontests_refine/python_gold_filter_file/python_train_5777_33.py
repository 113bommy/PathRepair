def answer(num):
    if num==0:
        return [0," "]
    if num==1:
        return [1,"1"]
    if num==2:
        return [1,"2"]
    if num==3:
        return [2,"1 3"]
    if num==4:
        return [4,"3 1 4 2"]

    start=1
    if num%2==0:
        mid=int(start+num/2)
    else:
        mid=int(start+num/2+1)
    ans=""
    k=0
    mid_f=0
    while(1):
        ans+=str(start)
        start+=1
        if mid_f==0:
            ans+=" "+ str(mid)+" "
            mid+=1

        if mid==num+1:
            mid_f=1
        if start>=num/2+1:
            break
    return [num,ans]

num=int(input())
a=answer(num)
print(a[0])
print(a[1])
