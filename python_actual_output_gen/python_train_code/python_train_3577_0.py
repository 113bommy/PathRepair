n,x = map(int,input().split())
A = list(map(int,input().split()))
cnt = [0 for i in range(max(A)+1)]
for i in A:
    cnt[i]+=1
if(len(set(A))<n):
    print("0")
else:
    flag = 0
    for i in range(n):
        if(cnt[A[i]&x]>1 and A[i]!=A[i]&x):
            flag = 1
    for i in range(n):
        A[i] = A[i]&x
    if(flag == 1):
        print("1")
    elif(len(set(A))<n):
        print("2")
    else:
        print("-1")