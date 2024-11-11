def operation(n):
    global arr
    global op
    for i in range(n):
        a = arr[0]
        b = arr[1]
        if a > b:
            del arr[1]
            arr.append(b)
        else:
            del arr[0]
            arr.append(a)
        op.append([a, b])


num = list(map(int, input().rstrip().split()))
arr = list(map(int, input().rstrip().split()))
op = []
eve=0
m=max(arr)
fi = 0
k=True
while k==True:
    if arr[0]!=m:
        operation(1)
        fi+=1
    else:
        k=False
        break
# print(arr,fi,op)
temp=list(arr[1:])
# print(temp)
for i in range(num[1]):
    a = int(input())
    if a<=fi:
        print(op[a - 1][0],op[a - 1][1])
    else:
        a-=fi
        print(arr[0],temp[ a % len(temp)-1 ])