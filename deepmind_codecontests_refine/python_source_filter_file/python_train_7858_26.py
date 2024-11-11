n = int(input())
num = list(map(int, input().split()))
ans = 0
count = 0
for i in range(n-1):
    if num[i+1]>=num[i]:
        count+=1
        print("currently considering", num[i], num[i+1])
    else:
        if count>=ans:
            ans = count+1
        count = 0
if count>=ans:
    ans = count +1
print(ans)