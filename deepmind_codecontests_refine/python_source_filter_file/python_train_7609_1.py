n = int(input())
remaining_keyboards = list(map(int, input().split()))
start = min(remaining_keyboards)
end = max(remaining_keyboards)
k = end - start - 1
for keyboard in remaining_keyboards:
    if keyboard != start and keyboard != end:
        k -= 1
print(k)