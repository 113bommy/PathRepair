n = int(input())
rank_before = []
rank_after = []
for _ in range(n):
    arr = list(map(int, input().split()))
    rank_before.append(arr[0])  # before round
    rank_after.append(arr[1]) # after round
    
def IsItRated(a,b):
    arr = sum([i-j for i,j in zip(a,b)])
    sorted_b = sorted(b, reverse=True)
    if arr != 0:
        return 'rated'
    else:
        if b != sorted_b:
            return 'unrated'
        else:
            return 'maybe'
            
ans = IsItRated(rank_before,rank_after)
print (ans)