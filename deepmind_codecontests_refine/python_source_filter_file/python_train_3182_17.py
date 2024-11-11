n = int(input())
arr = list(map(int,input().split()))

vowels = {'a','e','i','o','u'}
flag = True
for i in range(n):
    text = input()
    count=0
    for j in text:
        if(j in vowels):
            count+=1
    if(count!=arr[i]):
        flag = False
        break

if(flag): print("YES")
else: print("NO")