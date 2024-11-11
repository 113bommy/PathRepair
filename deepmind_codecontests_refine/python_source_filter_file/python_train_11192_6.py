m,n = input().rstrip().split(" ")
m = int(m)
n = int(n)
a = list(map(int,input().rstrip().split(" ")))
b = list(map(int,input().rstrip().split(" ")))
a = sorted(a)
bdic = {}
for it in range(n):
    bdic[it] = b[it]
# print(bdic)    
b = sorted(b)
count = 0
flag = 0
countdic = {}
for i in range(n):
    
    while(a[count] <= b[i]):
        count+=1
        print(count,i)
        if count==m:
            flag = -1
            # print("chalo bahar")
            break
    if flag == -1:
        break    
    countdic[b[i]] = count
# print(countdic)
if flag ==-1:
    for j in range(i,n):
        countdic[b[j]] = count
# print(countdic,bdic)        
for index, val in bdic.items():
    print(countdic[val],end=" ")        