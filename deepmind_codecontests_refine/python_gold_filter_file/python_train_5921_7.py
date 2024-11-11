tate =int(input())
yoko=int(input())
arr = [i+1 for i in range(tate)]
for j in range(yoko):
    rep1,rep2=input().split(",")
    rep1=int(rep1)-1
    rep2=int(rep2)-1
    arr[rep1],arr[rep2] = arr[rep2],arr[rep1]

for k in range(tate):
    print(arr[k])
