n = int(input())
arr = list(map(int, input().split()))
ans = []
c = min(arr)
[ans.append(i) for i in range(len(arr)) if arr[i] == c]
diff = len(ans)
for i in range(1, len(ans)):
    if ans[i] - ans[i-1] < diff:
        diff = ans[i] - ans[i-1]
print(diff)
