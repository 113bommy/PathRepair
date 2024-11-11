s = input()
k = int(input())
ar = list(map(int, input().split()))
best_letter = max(ar)
best_idx = ar.index(best_letter)
al = sorted(list('zxcvbnmasdfghjklqwertyuiop'))
best_letter = al[best_idx]
s = s + best_letter * k

func = 0
for i in range(len(s)):
    func += ar[al.index(s[i])] * (i+1)
    
print(func)