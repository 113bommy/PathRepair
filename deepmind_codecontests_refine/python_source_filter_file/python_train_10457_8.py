k,a,b=map(int,input().split())
s=input()
bal =len(s)
if bal>k*b or bal<k*a:
    print("No solution")
else:
    arr=[a]*k
    bal-=a*k
    inc=bal//k
    bal-=inc*k
    for i in range(k):
        arr[i]+=inc
    for i in range(bal):
        arr[i]+=1
    print(arr)
    for i in range(1,k):
        arr[i]+=arr[i-1]
    arr2=[s[:arr[0]]]
    for i in range(1,k):
        arr2.append(s[arr[i-1]:arr[i]])
    print(arr)
    for i in arr2:
        print(i)
