arr=[input().split() for i in range(5)]
for i in range(5):
    for j in range(5):
        if(arr[i][j])=='1':
            a=i
            b=j
            break
c=abs(a-1)+abs(b-1)
print(c)

