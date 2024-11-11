s = input()
K = int(input())
arr = set()
for i in range(len(s)):
    for j in range(i+1,min(i+1+K,len(s))):
        arr.add(s[i:j])
print(list(sorted(arr))[K-1])