#### B. Shooting

n = int(input())
arr = [int(x) for x in input().split()]
shots = []

seq=[[a,i] for i,a in enumerate(arr)]
A = sorted(seq)[::-1]

while len(arr)!=0:
    mx = max(arr)
    shots.append(mx*len(shots)+1)
    arr.remove(mx)
    
print(sum(shots))
print([A[i][1]+1 for i in range(n)])